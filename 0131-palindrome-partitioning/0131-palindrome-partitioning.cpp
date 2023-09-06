class Solution {
public:
    vector<vector<string>> ans;
    int n;
    
    bool isPalindrome(string s) {
        int i=0, j=s.length()-1, f=1;
        if(s.length()==1) {
            return 1;
        }
        while(i<=j) {
            if(s[i++]!=s[j--]) {
                f=0;
                break;
            }
        }
        return f;
    }
    
    void solve(int i, vector<string> temp, string &s) {
        if(i==n) {
            ans.push_back(temp);
            return;
        }
        
        for(int c=1;c<=n-i;c++) {
            string x=s.substr(i, c);
            if(isPalindrome(x)) {
                temp.push_back(x);
                solve(i+c, temp, s);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        n=s.length();
        if(n==1){
            ans.push_back(vector<string>{s});
            return ans;
        }
        vector<string> temp;
        solve(0, temp, s);
        return ans;
    }
};