class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<Node*> qu;
        qu.push(root);
        
        while(!qu.empty()){
            int n=qu.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                Node* level=qu.front();
                qu.pop();
                temp.push_back(level->val);
                for(int i=0;i<(level->children).size();i++){
                    qu.push((level->children)[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};