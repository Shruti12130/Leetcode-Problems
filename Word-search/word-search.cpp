class Solution {
public:
    int n, m, f;
    
    void solve(int i, int j, int k, string word, vector<vector<char>>& board) {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[k]) {
            return;
        }
        if(k>=word.length()-1) {
            f=1;
            return;
        } 
        
        char c=board[i][j];
        board[i][j]='*';
        solve(i-1, j, k+1, word, board);
        solve(i+1, j, k+1, word, board);
        solve(i, j-1, k+1, word, board);
        solve(i, j+1, k+1, word, board);
        board[i][j]=c;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(), m=board[0].size();
        f=0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]==word[0]) {
                    solve(i, j, 0, word, board);
                    if(f) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};
