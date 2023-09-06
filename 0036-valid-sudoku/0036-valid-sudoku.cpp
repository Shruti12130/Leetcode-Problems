class Solution {
public:
    
    bool isValid(int r, int c, char ch, vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            if(board[r][i] == ch) {
                return 0;
            }
            
            if(board[i][c]==ch) {
                return 0;
            }
            
            if(board[3*(r/3)+i/3][3*(c/3)+i%3] == ch) {
                return 0;
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<9;row++) {
            for(int col=0;col<9;col++) {
                if(board[row][col]!='.') {
                    char ch=board[row][col];
                    board[row][col]='.';
                    if(!isValid(row, col, ch, board)) {
                        return false;
                    }
                    board[row][col]=ch;
                }
            }
        }
        return true;
    }
};