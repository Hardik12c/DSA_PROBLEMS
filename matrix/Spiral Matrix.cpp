class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        
        
        int row_start=0;
        int column_start=0;
        int row_end=n-1;
        int column_end=m-1;
        
        
        vector<int> ans;
        while(row_start<=row_end && column_start<=column_end){
            for(int i=column_start;i<=column_end;i++){
                if(row_start<=row_end && column_start<=column_end){
                    ans.push_back(arr[row_start][i]);
                }                
            }
            row_start++;
            for(int i=row_start;i<=row_end;i++){
                if(row_start<=row_end && column_start<=column_end){
                    ans.push_back(arr[i][column_end]);
                }                
            }
            column_end--;
            for(int i=column_end;i>=column_start;i--){
                if(row_start<=row_end && column_start<=column_end){
                    ans.push_back(arr[row_end][i]);
                }                
            }
            row_end--;
            for(int i=row_end;i>=row_start;i--){
                if(row_start<=row_end && column_start<=column_end){
                    ans.push_back(arr[i][column_start]);
                }
            }
            column_start++; 
        }
        return ans;
        
    }
};