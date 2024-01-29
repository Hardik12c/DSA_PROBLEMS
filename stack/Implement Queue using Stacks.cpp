class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    void recurse(stack<int> &s,int &n){
        if(s.empty()){
            s.push(n);
            return;
        }
        int num=s.top();
        s.pop();
        recurse(s,n);
        s.push(num);
    }
    void push(int x) {
        recurse(s,x);
    }
    
    int pop() {
        int n=s.top();
        s.pop();
        return n;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};
