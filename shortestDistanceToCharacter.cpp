void binarySearch(vector<int>&arr, int &low, int &high, int v){
 
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if(arr[mid] == v)return;
        
        else if(v > arr[mid]){
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    
}

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        
        vector<int>indicesOfC;
        
        for(int i = 0; s[i]; i++){
            if(s[i] == c){
                indicesOfC.push_back(i);
            }
        }
        
        int n = indicesOfC.size();
        sort(indicesOfC.begin(), indicesOfC.end());
        
        vector<int>ans;
        
        for(int i = 0; s[i]; i++){
            
            if(s[i] == c){
                ans.push_back(0);
            }else{
                if(i < indicesOfC[0]){
                    ans.push_back(indicesOfC[0] - i);
                }else if(i > indicesOfC[n - 1]){
                    ans.push_back(i - indicesOfC[n - 1]);
                }else{
                    
                    int low = 0, high = n-1;            
                    binarySearch(indicesOfC, low, high, i);
                    ans.push_back( min(indicesOfC[low] - i, i - indicesOfC[high]));
                }
            }
        }
        
        return ans;
    }
};
