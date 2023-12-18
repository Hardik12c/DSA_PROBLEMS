class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0};
        for(int i=0;i<s1.size();i++){
            arr1[s1[i]-'a']++;
        }
        int j=0;
        int arr2[26]={0};
        for(int i=0;i<s2.size();i++){
            arr2[s2[i]-'a']++;
            if(i+1>=s1.size()){
                bool flag=true;
                for(int j=0;j<26;j++){
                    if(arr1[j]!=arr2[j]){
                        flag=false;
                        break;
                    }
                }
                if(flag) return true;
                arr2[s2[j]-'a']--;
                j++;
            }
        }
        return 0;
    }
};