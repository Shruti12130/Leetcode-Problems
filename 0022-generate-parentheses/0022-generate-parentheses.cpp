class Solution {
public:
    vector<string> parenthesis;
    
    void solve(int op, int close, int n, string ans) {
        if(op + close == 2*n) {
            parenthesis.push_back(ans);
            return;
        }
        if(op<n) {
            solve(op+1, close, n, ans+'(');
        } 
        if(op>close){
            //only insert the close tag when the no of open tag is greater than it.
            solve(op, close+1, n, ans+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(0, 0, n, "");
        return parenthesis;
    }
};