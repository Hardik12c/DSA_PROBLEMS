#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    int j=0;
    while(j<mCols){
        for(int i=0;i<nRows;i++){
            ans.push_back(arr[i][j]);
        }
        j++;
        if(j<mCols){
            for(int i=nRows-1;i>=0;i--){
                ans.push_back(arr[i][j]);
            }
            j++;
        }
    }
    return ans;
}