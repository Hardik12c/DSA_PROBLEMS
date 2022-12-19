class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int i=0;
        int prev=0;
        while(candies!=0){
            if(i>=num_people) i=0;
            int curr=prev+1;
            if(curr>candies){
                ans[i]+=candies;
                break;
            }
            ans[i]+=curr;
            candies-=curr;
            i++;
            prev=curr;
        }
        return ans;
    }
};