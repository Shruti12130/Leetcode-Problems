class Solution {
public:
    vector<string> res;
    
    void solve(int ind, string ans, string digits, vector<string> &mp) {
        int n = digits.length();//cout<<ind<<" "<<n<<endl;
        if(ind == n) {
            res.push_back(ans);
            return;
        }
        
        int c = digits[ind]-'0'; 
        string str = mp[c];
        for(auto ch: str) {
            ans+=ch;
            solve(ind+1, ans, digits, mp);
            ans.pop_back();
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