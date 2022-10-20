class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n=mat.size();
        int m=mat[0].size();
        bool flag=true;
        for(int i=0;i<m;i++){
            int k=i;
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(mat[j][i]);
                i--;
                if(i<0 ||j==n) break;
            }
            if(flag){
                flag=false;
                reverse(temp.begin(),temp.end());
            } 
            else flag=true;
            ans.insert(ans.end(),temp.begin(),temp.end());
            i=k;
        }
        for(int i=1;i<n;i++){
            int k=i;
            vector<int> temp;
            for(int j=m-1;j>=0;j--){
                temp.push_back(mat[i][j]);
                i++;
                if(i==n ||j<0) break;
            }
            if(flag){
                flag=false;
                reverse(temp.begin(),temp.end());
            } 
            else flag=true;
            i=k;            
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return ans;
    }
};