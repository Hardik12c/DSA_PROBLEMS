class Solution {
    public int[] leftRigthDifference(int[] nums) {
        int rightsum=0;
        for(int i:nums){
            rightsum+=i;
        }
        int leftsum=0;
        for(int i=0;i<nums.length;i++){
            rightsum-=nums[i];
            int num=nums[i];
            nums[i]=Math.abs(leftsum-rightsum);
            leftsum+=num;
        }
        return nums;
    }
}