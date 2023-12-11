class Solution {
public:
    int findMaxIndex(vector<int> nums){
        int mx=INT_MIN;
        int index;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mx){
                index=i;
                mx=nums[i];
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high=mat.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int mxInd=findMaxIndex(mat[mid]);
            int top=mid-1>=0?mat[mid-1][mxInd]:-1;
            int bottom=mid+1<mat.size()?mat[mid+1][mxInd]:-1;
            if(mat[mid][mxInd]>top && mat[mid][mxInd]>bottom) return {mid,mxInd};
            else if(mat[mid][mxInd]<bottom) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};