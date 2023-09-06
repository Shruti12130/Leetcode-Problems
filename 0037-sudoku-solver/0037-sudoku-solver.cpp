class Solution {
public:
    bool isValid(int row, int col, char ch, vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            //Checking character ch validity for row
            if(board[row][i] == ch) {
                return 0;
            }
            
            //Checking character ch validity for col
            if(board[i][col] == ch) {
                return 0;
            }
            
            //Checking character ch validity for grid
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch) {
                return 0;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int row=0; row<9; row++) {
            for(int col=0; col<9; col++) {
                if(board[row][col]=='.') {
                    for(char ch='1'; ch<='9'; ch++) {
                        //check if the curr num would be valid for (row, col) cell or not
                        if(isValid(row, col, ch, board)) {
                            board[row][col] = ch;
                            if(solve(board)) {
                                return true;
                            } else {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;  //backtrack to previous filled values
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};