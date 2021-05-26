bool isSafe(vector<string>&solution, int row, int col){
        
    // check row
    int n = solution.size();
    
    for(int j = 0; j <= col; j++){
        if(solution[row][j] == 'Q')
            return false;
    }
    
    //checking column
    
    for(int i = 0; i <= row; i++){
        if(solution[i][col] == 'Q')
            return false;
    }
    
    
    // checking left diagonal
    
    int r = row, c = col;
    while(row >= 0 && col >= 0){
        if(solution[row][col] == 'Q')
            return false;
        
        row--;
        col--;
    }
    
    // checking right diagonal
    row = r; col = c;
    while(row >= 0 && col < n){
        if(solution[row][col] == 'Q')
            return false;
        
        row--;
        col++;
    }
    
    
    return true;
    
}

void NQueens(vector<string>&solution, vector<vector<string>> &solutions, int row, int n, string s){
    
    if(row == n){
        solutions.push_back(solution);
        return;
    }
    
    for(int col = 0; col < n; col++){
        if(isSafe(solution, row, col)){
            solution[row][col] = 'Q';
            NQueens(solution, solutions, row + 1, n, s);
            solution[row] = s;
        }
    }
    
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        if(n == 1){
            return {{"Q"}};
        }
        
        string s = "";
        for(int i = 0; i < n; i++){
            s += ".";
        }
        
        vector<string> solution(n);
        for(int i = 0; i < n; i++){
            solution[i] = s;
        }
        
        // for(auto row : solution){
        //     for(auto col : row){
        //         cout<<col<<' ';
        //     }
        //     cout<<'\n';
        // }
        vector<vector<string>> solutions;
        
        NQueens(solution, solutions, 0, n, s);
        
        
        return solutions;
        
    }
};
