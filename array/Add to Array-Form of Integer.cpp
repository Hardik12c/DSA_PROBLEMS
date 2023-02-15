class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int ind=nums.size()-1;
        int carry=0;
        while(k!=0 && ind>=0){
            int num=k%10;
            k/=10;
            int sum=carry+num+nums[ind];
            nums[ind]=sum%10;
            carry=sum/10;
            ind--;
        }
        cout<<carry<<endl;
        while(carry!=0 || k!=0){
            if(ind<0){
                int num=k%10;
                int sum=carry+num;
                k=k/10;
                nums.insert(nums.begin(),sum%10);
                carry=sum/10;
            }else{
                int sum=nums[ind]+carry;
                nums[ind]=sum%10;
                carry=sum/10;
                ind--;
            }
        }
        return nums;
    }
};