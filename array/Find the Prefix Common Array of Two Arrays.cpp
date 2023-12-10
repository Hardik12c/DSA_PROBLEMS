class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;
        vector<int> ans;
        for(int i=0;i<A.size();i++){
            mpp1[A[i]]++;
            mpp2[B[i]]++;
            int count=0;
            for(auto it:mpp1){
                if(mpp2.find(it.first)!=mpp2.end()){
                    count+=min(mpp2[it.first],it.second);
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};