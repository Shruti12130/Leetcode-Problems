class Solution {
public:
    vector<string> ans;
    int n;
    
    void solve(int i, string s, string digits, vector<string> &letters) {
        if(i==n) {
            ans.push_back(s);
            return;
        }
        
        int k=digits[i]-'0';
        string str=letters[k];
        for(auto x: str) {
            solve(i+1, s+x, digits, letters);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> letters{"", "", "abc", "def", "ghi", "jkl", "mno", 
                                "pqrs", "tuv", "wxyz"};
        
        n=digits.length();
        if(n==0) {
            return ans;
        }
        solve(0, "", digits, letters);
        return ans;
    }
};