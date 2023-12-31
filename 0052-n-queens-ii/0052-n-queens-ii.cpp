class Solution {
public:
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
    
    int solve(int col, int n, vector<string> &temp) {
        if(col==n) {
            return 1;
        }
        
        int ans=0;
        for(int row = 0; row < n; row++) {
            if(canPlaceQ(row, col, temp)) {
                temp[row][col]='Q';
                ans += solve(col+1, n, temp);
                temp[row][col]='.';
            } 
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++) {
            s+='.';
        }
        vector<string> temp;
        for(int i=0;i<n;i++) {
            temp.push_back(s);
        }
        return solve(0, n, temp);
    }
};