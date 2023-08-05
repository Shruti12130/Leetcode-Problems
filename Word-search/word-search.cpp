class Solution {
public:
    int n, m, f;
    
    void solve(int i, int j, int k, string word, vector<vector<bool>> &vis, vector<vector<char>>& board) {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || board[i][j]!=word[k]) {
            return;
        }
        if(k>=word.length()-1) {
            f=1;
            return;
        } 
        
        vis[i][j]=1;
        solve(i-1, j, k+1, word, vis, board);
        solve(i+1, j, k+1, word, vis, board);
        solve(i, j-1, k+1, word, vis, board);
        solve(i, j+1, k+1, word, vis, board);
        vis[i][j]=0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(), m=board[0].size();
        vector<vector<bool>> vis(n+1, vector<bool>(m+1, 0));
        f=0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]==word[0]) {
                    solve(i, j, 0, word, vis, board);
                    if(f) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};
