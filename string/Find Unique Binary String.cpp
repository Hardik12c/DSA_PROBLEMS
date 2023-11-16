class Solution {
public:
    string createBinaryString(string s,int n,vector<string> nums){
        if(s.length()>=n){
            if(find(nums.begin(),nums.end(),s)!=nums.end()){
                return "";
            }
            return s;
        }
        s+='0';
        string zeroMade=createBinaryString(s,n,nums);
        if(zeroMade!="") return zeroMade;
        s.pop_back();
        s+='1';
        string oneMade=createBinaryString(s,n,nums);
        if(oneMade!="") return oneMade;
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        return createBinaryString("",nums[0].length(),nums);
    }
};