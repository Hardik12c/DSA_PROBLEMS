class compare{
    public:
    bool operator()(pair<char,int> a,pair<char,int> b){
        return a.second<b.second;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare> pq;
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++) mpp[s[i]]++;
        for(auto it:mpp){
            pq.push({it.first,it.second});
        }
        string ans="";
        pair<char,int> p={'h',0};
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            ans+=temp.first;
            temp.second--;
            if(p.second>0){
                pq.push(p);
            }
            p=temp;
        }
        if(ans.length()==s.length()) return ans;
        return "";
    }
};