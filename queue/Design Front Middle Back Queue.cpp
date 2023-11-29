class FrontMiddleBackQueue {
public:
    deque<int> qu;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        qu.push_front(val);
    }
    
    void pushMiddle(int val) {
        int n=qu.size();
        int mid=n/2;
        stack<int> st;
        while(mid!=0){
            st.push(qu.front());
            qu.pop_front();
            mid--;
        }
        qu.push_front(val);
        while(!st.empty()){
            qu.push_front(st.top());
            st.pop();
        }
    }
    
    void pushBack(int val) {
        qu.push_back(val);
    }
    
    int popFront() {
        if(qu.empty()) return -1;
        int num=qu.front();
        qu.pop_front();
        return num; 
    }
    
    int popMiddle() {
        if(qu.empty()) return -1;
        int n=qu.size();
        int mid=n&1?n/2:(n/2)-1;
        stack<int> st;
        while(mid!=0){
            st.push(qu.front());
            qu.pop_front();
            mid--;
        }
        int num=qu.front();
        qu.pop_front();
        while(!st.empty()){
            qu.push_front(st.top());
            st.pop();
        }
        return num;
    }
    
    int popBack() {
        if(qu.empty()) return -1;
        int num=qu.back();
        qu.pop_back();
        return num;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */