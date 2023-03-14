class Solution {
public:
    unordered_map<string,string> mpp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shorturl="http://";
        string temp="";
        for(int i=longUrl.length()-1;i>=0;i--){
            if((longUrl[i]>=97 &&longUrl[i]<=122)||(longUrl[i]>=65 && longUrl[i]<=90)){
                temp+=longUrl[i];
            }else break;
        }
        reverse(temp.begin(),temp.end());
        shorturl+=temp;
        shorturl+='/';
        bool flag=true;
        int num=0;
        for(int i=8;i<longUrl.length();i++){
            if(longUrl[i]=='/'){
                num=0;
                flag=true;
                continue;
            } 
            if(num==3) flag=false;
            if(!flag) continue;
            shorturl+=longUrl[i];
            num++;
        }
        mpp[shorturl]=longUrl;
        return shorturl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));