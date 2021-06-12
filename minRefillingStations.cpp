class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        priority_queue<int>q;
    
        int reachable = startFuel;
        int refillings = 0;
    
    
        for(auto station : stations){
            
            int nextStationX = station[0];
            int fuelAtNextStation = station[1];
            
            while(reachable < nextStationX){
                if(q.empty())
                    return -1;
                
                reachable += q.top(); q.pop();
                refillings ++;
            }
            
            q.push(fuelAtNextStation);
        }
        
        while(reachable < target){
            if(q.empty()){
                return -1;
            }
            
            reachable += q.top(); q.pop();
            refillings ++;
        }
        
        return refillings;
        
    }
};