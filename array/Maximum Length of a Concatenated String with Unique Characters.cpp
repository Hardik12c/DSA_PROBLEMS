class Solution {
public:
    bool check(string s){
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
            if(mpp[s[i]]>1){
                return false;
            }
        }
        return true;
    }
    void maxstring(vector<string> arr,string s,int &ans,int i){
        if(i>=arr.size()){
            int n=s.length();
            ans=max(ans,n);
            return;
        }
        maxstring(arr,s,ans,i+1);
        if(check(s+arr[i])){
            s+=arr[i];
            maxstring(arr,s,ans,i+1);
        }
    }
    int maxLength(vector<string>& arr) {
        int ans=0;
        string s="";
        maxstring(arr,s,ans,0);
        return ans;
    }
};