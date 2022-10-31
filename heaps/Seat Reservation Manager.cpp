class SeatManager {
public:
    priority_queue<int,vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i=0;i<n;i++){
            pq.push(i+1);
        }
    }
    
    int reserve() {
        int k=pq.top();
        pq.pop();
        return k;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};