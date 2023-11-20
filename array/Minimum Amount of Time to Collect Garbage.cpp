class Solution {
public:
    int getcalc(vector<int> travel,char c,vector<string> garbage){
        int ans=0;
        int lastIndex=0;
        for(int i=0;i<garbage.size();i++){
            string s=garbage[i];
            int count=0;
            for(int j=0;j<s.length();j++){
                if(s[j]==c){
                    count++;
                }
            }
            if(count!=0 && i!=0){
                for(int j=lastIndex;j<i;j++){
                     ans+=travel[j];
                }
                lastIndex=i;
            }
            ans+=count;
        }
        return ans;
    }

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        return getcalc(travel,'G',garbage)+getcalc(travel,'P',garbage)+getcalc(travel,'M',garbage);
    }
};