class NumMatrix {
    
    int[][] sum;
    
    public NumMatrix(int[][] matrix) {
        
        sum = matrix;
        
        int m = matrix.length;
        int n = matrix[0].length;
        
        sum[0][0] = matrix[0][0];
        for(int i = 1; i < m; i++){
            sum[i][0] = matrix[i][0] + sum[i - 1][0]; 
        }
        for(int j = 1; j < n; j++){
            sum[0][j] = matrix[0][j] + sum[0][j - 1];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }        
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sumAbove = row1 > 0 ? sum[row1 - 1][col2] : 0;
        int sumLeft = col1 > 0 ? sum[row2][col1 - 1] : 0;
        int sumDiag = row1 > 0 && col1 > 0 ? sum[row1 - 1][col1 - 1] : 0;
        int sumTotal = sum[row2][col2];
        
        return sumTotal - sumLeft - sumAbove + sumDiag;
        
    }
}

