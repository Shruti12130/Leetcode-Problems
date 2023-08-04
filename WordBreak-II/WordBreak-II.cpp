class Solution {
public:
    vector<string> ans;
    
    void solve(int i, int n, string word, string s, unordered_set<string> &st) {
        if(i==n) {
            word.pop_back();
            ans.push_back(word);
            return;
        }
        
        
        for(int k=i;k<n;k++) {
            string temp=s.substr(i, k-i+1);
            if(st.count(temp)) {
                solve(k+1, n, word+temp+" ", s, st);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        solve(0, n, "", s, st);

        return ans;
    }
};
