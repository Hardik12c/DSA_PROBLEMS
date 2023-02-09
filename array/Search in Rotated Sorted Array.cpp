class Solution {
public:
    int findpivot(vector<int> &nums){
        int n=nums.size();
        int s=0;int e=n-1;
        int mid=(s+e)/2;
        int start=0;
        while(s<e){
            cout<<mid<<endl;
            if(mid-1>=0&& mid+1<n&&nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                start=mid;
                break;
            }else if(nums[mid]<nums[e]) e=mid-1;
            else s=mid+1;
            mid=(s+e)/2;
        }
        if(s==e) start=s;
        return start;
    }
    int binary_search(int s,int e,vector<int> &nums,int target){
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
            mid=(s+e)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start= findpivot(nums);
        if(target>=nums[start]&&target<=nums[n-1]){
            return binary_search(start,n-1,nums,target);
        }
        cout<<start<<endl;
        return binary_search(0,start-1,nums,target);
    }
};