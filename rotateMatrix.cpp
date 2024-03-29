class Solution {
public:
   
    void rotate(vector<vector<int>>& matrix) {
        
        
        int n = matrix[0].size();
        
        // transpose the matrix
        
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i; j++){
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
            }
        }
        
        // for(auto x : matrix){
        //     for(auto y : x){
        //         cout<<y<<' ';
        //     }
        //     cout<<'\n';
        // }
        
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n; j++){
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        
        
    }
};
