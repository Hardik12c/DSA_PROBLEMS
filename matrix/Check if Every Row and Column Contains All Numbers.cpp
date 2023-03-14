class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            for(int j=0;j<n;j++){
                mpp[matrix[i][j]]++;
            }
            for(auto it:mpp){
                if(it.second!=1) return false;
            }
            for(int j=0;j<n;j++){
                mpp[matrix[j][i]]++;
            }
            for(auto it:mpp){
                if(it.second!=2) return false;
            }
        }        
        return true;
    }
};