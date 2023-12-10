class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            vector<int> newvec=nums;
            sort(newvec.begin()+l[i],newvec.end()-(nums.size()-r[i]-1));
            int index1=l[i];
            int index2=r[i];
            int d=newvec[index1+1]-newvec[index1];
            bool isAirth=true;
            for(int j=index1+2;j<=index2;j++){
                if(newvec[j]-newvec[j-1]!=d){
                    isAirth=false;
                    break;
                }
            }
            ans.push_back(isAirth);
        }
        return ans;
    }
};