class Solution {
    int solve(vector<int>& stones, int left, int right, int sum, int** dp){
        
        if(left == right){
            return 0;
        }
        
        if(right - left == 1){
            return max(stones[right], stones[left]);
        }
        
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        
        return dp[left][right] = max(sum - stones[left] - solve(stones, left + 1, right, sum - stones[left], dp),
                             sum - stones[right] - solve(stones, left, right - 1, sum - stones[right], dp));
                
    }
public:
    int stoneGameVII(vector<int>& stones) {
        
        int n = stones.size();
        
        int **dp = new int*[n];
        for(int i = 0; i < n; i++){
            dp[i] = new int[n];
            for(int j = 0; j < n; j++){
                dp[i][j] = -1;
            }
        }
        
        int sum = 0;
        
        for(int x : stones){
            sum += x;
        }
        
        return solve(stones, 0, n - 1, sum, dp);
        
    }
};