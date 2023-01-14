class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        unordered_map<string,int> mpp;
        string ans;
        int mx=INT_MIN;

        for(int i=0;i<senders.size();i++){
            string user=senders[i];
            string temp="";
            for(int j=0;j<messages[i].size();j++){
                if(messages[i][j]==' '){
                    mpp[user]++;
                    temp="";
                }else{
                    temp+=messages[i][j];
                }
            }
            if(temp!="") mpp[user]++;

            if(mpp[user]>mx){
                ans=user;
                mx=mpp[user];
            }else if(mpp[user]==mx){
                ans=max(user,ans);
            }

        }
        return ans;
    }
};