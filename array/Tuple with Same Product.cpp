class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mpp[nums[i]*nums[j]]++;
            }
        }
        for(auto i:mpp){
            if(i.second>1){
                    // number of product
                    int np=i.second;
                    // number of combination
                    int nc=np*(np-1)/2;
                    // ways to get permutations from that
                    ans+=nc*8;
                }
        }
        return ans;
    }
};