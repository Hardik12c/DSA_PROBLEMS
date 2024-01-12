class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int ind=1;
        while(true){
            if(memory2>memory1 && memory2>=ind){
                memory2-=ind;
            }else if(memory1>=memory2 && memory1>=ind){
                memory1-=ind;
            }else{
                break;
            }
            ind++;
        }
        return {ind,memory1,memory2};
    }
};