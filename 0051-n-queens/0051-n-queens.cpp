class Solution {
public:
    vector<vector<string>> ans;
    
    bool canPlaceQ(int row, int col, vector<string> &temp) {
        int r=row, c=col, n=temp.size();
        while(r>=0 && c>=0) {
            if(temp[r][c]=='Q') {
                return false;
            }
            r--;
            c--;
        }
        
        r=row, c=col;
        while(c>=0) {
            if(temp[r][c]=='Q') {
                return false;
            }
            c--;
        }
        
        r=row, c=col;
        while(r<n && c>=0) {
            if(temp[r][c]=='Q') {
                return false;
            }
            r++;
            c--;
        }
        return true;
    }
    
    void solve(int col, int n, vector<string> &temp) {
        if(col==n) {
            ans.push_back(temp);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(canPlaceQ(row, col, temp)) {
                temp[row][col]='Q';
                solve(col+1, n, temp);
                temp[row][col]='.';
            } 
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++) {
            s+='.';
        }
        vector<string> temp;
        for(int i=0;i<n;i++) {
            temp.push_back(s);
        }
        solve(0, n, temp);
        return ans;
    }
};