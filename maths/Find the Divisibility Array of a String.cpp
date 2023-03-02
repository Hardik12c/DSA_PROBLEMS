class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int p=0;
        long long number=0;
        vector<int> ans;
        for(int i=0;i<word.size();i++){
            int num=word[i]-'0';
            number=(number*(10)+num)%m;
            p++;
            if(number==0){
                ans.push_back(1);
            }else ans.push_back(0);
            
        }
        return ans;
    }
};