class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> isvisited(rooms.size(),0);
        queue<int> qu;
        qu.push(0);
        isvisited[0]=1;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            for(int i=0;i<rooms[node].size();i++){
                if(!isvisited[rooms[node][i]]){
                    isvisited[rooms[node][i]]=1;
                    qu.push(rooms[node][i]);
                }
            }
        }
        for(int i=0;i<isvisited.size();i++){
            if(!isvisited[i]) return false;
        }
        return true;
    }
};