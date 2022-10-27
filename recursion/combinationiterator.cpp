class CombinationIterator {
public:
    int i=0;
    vector<string> ans;
    void recursive(int k,vector<string> &ans,string s,int i,string main){
        if(i>main.length()) return;
        if(s.length()==k){
            ans.push_back(s);
            return;
        }
        recursive(k,ans,s,i+1,main);
        s.push_back(main[i]);
        recursive(k,ans,s,i+1,main);
    }
    CombinationIterator(string characters, int combinationLength) {
        string s="";
        recursive(combinationLength,ans,s,0,characters);
        sort(ans.begin(),ans.end());
    }
    string next() {
        return ans[i++];
    }
    
    bool hasNext() {
        if(i<ans.size()) return true;
        else return false;
    }
};