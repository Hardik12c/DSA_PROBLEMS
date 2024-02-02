class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int num=1;
        int count=2;
        vector<int> ans;
        while(num<=high){
            int next=count;
            int nextnum=num;
            int div=pow(10,count-1);
            while(nextnum<low && next<10){
                nextnum=nextnum*10+next;
                nextnum=nextnum%div;
                next++;
            }
            if(nextnum<=high && nextnum>=low) next--;

            while(nextnum<=high && next<10){
                next++;
                ans.push_back(nextnum);
                nextnum=nextnum*10+next;
                nextnum=nextnum%div;
            }
            num=num*10+count;
            count++;
        }
        return ans;
    }
};