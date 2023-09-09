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
        if(!(temp[ind]>='0' && temp[ind]<='9')) {
            if(ch>='a' && ch<='z') {
                solve(ind+1, temp);
                temp[ind]=ch-32;
                solve(ind+1, temp);
                temp[ind]=ch;
            } else {
                solve(ind+1, temp);
                temp[ind]=ch+32;
                solve(ind+1, temp);
                temp[ind]=ch;
            }
        } else {
            solve(ind+1, temp);
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        n=s.length();
        solve(0, s);
        return ans;
    }
};