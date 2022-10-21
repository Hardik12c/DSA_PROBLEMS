class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        bool flag=true;
        while(i<haystack.size()){
            if(haystack[i]==needle[0]){
                string k=haystack.substr(i,needle.size());
                if(needle==k){
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};