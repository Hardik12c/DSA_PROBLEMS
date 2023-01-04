class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> tasksmap;
        int ans=0;
        for(int i=0;i<tasks.size();i++){
            tasksmap[tasks[i]]++;
        }
        for(auto i:tasksmap){
            int num=i.second;
            if(num<2) return -1;
            if(num%3==0){
                ans+=num/3;
                continue;
            }
            else if(num&1){
                num=num-3;
            }else{
                num-=2;
            }
            ans+=1;
            if(num%3==1){
                num-=2;
                ans++;
            }            
            ans+=num/3;
            num=num%3;
            ans+=num/2;
        }
        return ans;
        return 0;
    }
};