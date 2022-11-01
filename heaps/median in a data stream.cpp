class MedianFinder {
public:
    double M=INT_MIN;
    priority_queue<int> mxH;
    priority_queue<int,vector<int>,greater<int>>mnH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(signum(mxH.size(),mnH.size())==0){
            if(num>M){
                mnH.push(num); 
                M=mnH.top();   //as size of mnH is greater so its top will be the median
            }else{
                mxH.push(num);
                M=mxH.top();   //as size of mxH is greater so its top will be the median
            }
        }else if(signum(mxH.size(),mnH.size())==1){
            if(num>M){
//now if we push the element into mnH then the size difference between both the heaps will be 2 and we want 1 or equal so first pop out and element from min heap and push it into max heap
                int k=mnH.top();
                mnH.pop();
                mxH.push(k);
                mnH.push(num);
// we have popped one element from mnh and pushed one element in it so its size remains same but we have pushed one element in mxH so both of their size now equal
                M=((mxH.top()+mnH.top())/2.0);
            }else{
                mxH.push(num);
                M=((mxH.top()+mnH.top())/2.0);
            }
        }else{
            if(num>M){
                mnH.push(num);
                M=((mxH.top()+mnH.top())/2.0);
            }else{
//following the step used above
                int k=mxH.top();
                mxH.pop();
                mnH.push(k);
// we have popped one element from mnh and pushed one element in it so its size remains same but we have pushed one element in mxH so both of their size now equal               
                mxH.push(num);
                M=((mxH.top()+mnH.top())/2.0);
            }
        }
    }
    
    double findMedian() {
        return M;
    }

    int signum(int a,int b){
        if(a==b) return 0;
        else if (a<b) return 1;
        else return -1;
    }
};