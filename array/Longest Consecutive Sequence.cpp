class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++) st.insert(nums[i]);
        int longestseq=0;
        for(int no:st){
            if(st.count(no-1)) continue;
            int start=1;
            while(st.count(no+start)) start++;
            longestseq=max(longestseq,start);
        }
        return longestseq;
    }
};