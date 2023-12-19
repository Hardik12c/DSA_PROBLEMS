class BrowserHistory {
public:
    vector<string> ans;
    int i=0;
    int size=0;
    BrowserHistory(string homepage) {
        ans.push_back(homepage);
        size=1;
    }
    
    void visit(string url) {
        if(i+1<ans.size()){
            ans[i+1]=url;
            i++;
            size=i+1;
        }else{
            ans.push_back(url);
            i++;
            size=ans.size();
        }
    }
    
    string back(int steps) {
        if(i-steps>=0){
            i=i-steps;
        }else{
            i=0;
        }
        return ans[i];
    }
    
    string forward(int steps) {
        if(i+steps<size){
            i=i+steps;
        }else{
            i=size-1;
        }
        return ans[i];
    }
};
