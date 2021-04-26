class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        
        int i = 0;
        
        priority_queue<int>bricks_queue;
        
        for(; i < h.size() - 1; i++){
            int d = h[i + 1] - h[i];
            
            if(d <= 0)continue;
            
            if(b >= d){
                bricks_queue.push(d);
                b -= d;
            }else if(l > 0){
                
                if(bricks_queue.size() != 0){
                    int x = bricks_queue.top();
                
                    if(d < x){
                        b += x;
                        b -= d;
                        bricks_queue.pop();
                        bricks_queue.push(d);
                    }
                }
                
                l--;
                
            }
            
            else
                break;
        }
        
        return i;
        
    }
};
