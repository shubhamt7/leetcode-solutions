bool compare(vector<int>&a, vector<int>&b){
    
    return a[1] < b[1];
    
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), compare);
        
        priority_queue<int> maxHeap;
        
        int timeElapsed = 0;
        
        for(auto course : courses){
            
            if(timeElapsed + course[0] <= course[1]){
                timeElapsed += course[0];
                maxHeap.push(course[0]);
            }else if(!maxHeap.empty() && course[0] < maxHeap.top()){
                timeElapsed -= maxHeap.top(); maxHeap.pop();
                timeElapsed += course[0];
                maxHeap.push(course[0]);
            }else{
                continue;
            }
            
        }
        
        return maxHeap.size();
        
    }
};
