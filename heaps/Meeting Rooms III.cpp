class compare {
public:
    bool operator()(pair<int, long long> a, pair<int, long long> b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0);
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<int, long long>, vector<pair<int, long long>>,
                       compare>
            pq;
        priority_queue<int, vector<int>, greater<int>> idx;
        for (int i = 0; i < n; i++) {
            idx.push(i);
        }
        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            while (!pq.empty() && pq.top().second <= start) {
                idx.push(pq.top().first);
                pq.pop();
            }
            if (pq.size() < n) {
                rooms[idx.top()]++;
                pq.push({idx.top(), end});
                idx.pop();
            } else {
                pair<int, long long> top = pq.top();
                pq.pop();
                pq.push({top.first, top.second + end - start});
                rooms[top.first]++;
            }
        }
        int ans = INT_MIN;
        int mx = 0;
        for (int i = 0; i < rooms.size(); i++) {
            if (rooms[i] > ans) {
                ans = rooms[i];
                mx = i;
            } else if (rooms[i] == ans) {
                mx = i < mx ? i : mx;
            }
        }
        return mx;
    }
};