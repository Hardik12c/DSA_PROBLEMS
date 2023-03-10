class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> mpp;
        vector<string> ans;
        for(int i=0;i<cpdomains.size();i++){
            string s=cpdomains[i];
            int pos=s.find(' ');
            int count=stoi(s.substr(0,pos));
            string newdomain=s.substr(pos+1);
            mpp[newdomain]+=count;

            for(int j=0;j<newdomain.size();j++){
                if(newdomain[j]=='.'){
                    string temp=newdomain.substr(j+1);
                    mpp[temp]+=count;
                }
            }
        }
        for(auto it:mpp){
            ans.push_back(to_string(it.second)+" "+it.first);
        }
        return ans;
    }
};