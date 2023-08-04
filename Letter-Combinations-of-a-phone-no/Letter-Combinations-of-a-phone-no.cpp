class Solution {
public:
    vector<string> res;
    
    void solve(int ind, string ans, string digits, vector<string> &mp) {
        int n = digits.length();
        if(ind == n) {
            res.push_back(ans);
            return;
        }
        
        for(int j=ind;j<n;j++) {
            int c = digits[j]-'0'; 
            string str = mp[c];
            for(auto ch: str) {
                solve(j+1, ans+ch, digits, mp);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return res;
        }
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", 
                             "pqrs", "tuv", "wxyz"};
        
        string ans="";
        solve(0, ans, digits, mp);
        return res;
    }
};
