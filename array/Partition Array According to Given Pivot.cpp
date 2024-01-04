class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int j=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }else if(nums[i]>pivot){
                nums[j]=nums[i];
                j++;
            }
        }
        int n=ans.size();
        for(int i=0;i<(nums.size()-n-j);i++){
            ans.push_back(pivot);
        }
        for(int i=0;i<j;i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};