class Solution {
public:
    vector<string> ans;
    int n;
    
    void solve(int ind, string temp) {
        if(ind==n) {
            ans.push_back(temp);
            return;
        }
        
        char ch=temp[ind];
        solve(ind+1, temp);
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
            if(ch>='a' && ch<='z') {
                temp[ind]=ch-32;
                solve(ind+1, temp);
                temp[ind]=ch;
            } else {
                temp[ind]=ch+32;
                solve(ind+1, temp);
                temp[ind]=ch;
            }
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        n=s.length();
        solve(0, s);
        return ans;
    }
};