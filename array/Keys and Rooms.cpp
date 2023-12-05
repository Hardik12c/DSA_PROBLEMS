class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(),0);
        visited[0]++;
        vector<int> store;
        store.insert(store.end(),rooms[0].begin(),rooms[0].end());
        for(int i=0;i<store.size();i++){
            if(visited[store[i]]==0){
            visited[store[i]]++;
            store.insert(store.end(),rooms[store[i]].begin(),rooms[store[i]].end());
            }
        }
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
};