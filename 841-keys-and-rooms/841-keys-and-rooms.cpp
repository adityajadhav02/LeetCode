class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;
        
        queue<int> roomToVisit;
        roomToVisit.push(0);
        
        while(!roomToVisit.empty()){
            int curr_room = roomToVisit.front();
            roomToVisit.pop();
            
            visited.insert(curr_room);
            
            for(int k: rooms[curr_room]){
                if(visited.find(k) == visited.end())
                    roomToVisit.push(k);
            }
        }
        return visited.size() == n;
    }
};