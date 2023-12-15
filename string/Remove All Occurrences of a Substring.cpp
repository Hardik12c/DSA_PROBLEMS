class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)<s.size()){
            s.erase(s.find(part),part.size());
        }
        return s;
    }
};

//another solution
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string another=s;
        int j=0;
        for(int i=0;i<s.length();i++){
            another[j]=s[i];
            j++;
            if(j>=part.size() && another.substr(j-part.size(),part.size())==part){
                j-=part.size();
            }
        }

        return another.substr(0,j);
    }
};