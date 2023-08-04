class Solution {
public:
    vector<string> ans;
    
    void solve(string word, unordered_set<string> &st) {
        int len=word.length();
        vector<bool> dp(len+1, 0);
        dp[0]=true;
        st.erase(word);
        
        for(int i=1;i<=len;i++) {
            for(int j=0;j<i;j++) {
                string temp=word.substr(j, i-j);
                if(st.count(temp) && dp[j]) {
                    dp[i]=true;
                    break;
                } 
            }
        }
        if(dp[len]) {
            ans.push_back(word);
        }
        st.insert(word);
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        unordered_set<string> st(words.begin(), words.end());
        
        for(int i=0;i<n;i++) {
            solve(words[i], st);
        }
        
        return ans;
    }
};
