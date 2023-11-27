class MyLinkedList {
public:
    vector<int> ans;
    MyLinkedList() {
    }
    
    int get(int index) {
        return index>=ans.size()? -1:ans[index];
    }
    
    void addAtHead(int val) {
        vector<int> newans;
        newans.push_back(val);
        newans.insert(newans.end(),ans.begin(),ans.end());
        ans=newans;
        
    }
    
    void addAtTail(int val) {
        ans.push_back(val);
        
    }
    
    void addAtIndex(int index, int val) {
        if(index>ans.size()) return ;
        vector<int> newans;
        for(int i=0;i<index;i++){
            newans.push_back(ans[i]);
        }
        newans.push_back(val);
        newans.insert(newans.end(),ans.begin()+index,ans.end());
        ans=newans;
    }
    
    void deleteAtIndex(int index) {
        if(index>=ans.size()) return;
        vector<int> newans;
        for(int i=0;i<index;i++){
            newans.push_back(ans[i]);
        }
        newans.insert(newans.end(),ans.begin()+index+1,ans.end());
        ans=newans;
    }
};