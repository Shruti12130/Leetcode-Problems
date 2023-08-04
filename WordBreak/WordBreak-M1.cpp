static int t[301];
class Solution {
public:
    
    bool solve(string s, int i, unordered_set<string> mp)
    {
        if(i>=s.length())
            return 1;
        
        if(t[i]!=-1)
            return t[i];
        
        for(int j=i;j<s.length();j++){
            if(mp.find(s.substr(i, j-i+1))!=mp.end() && solve(s, j+1, mp))
                return t[i]=1;
        }
        return t[i]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t, -1, sizeof(t));
        int n = s.length();
        unordered_set<string> mp(wordDict.begin(), wordDict.end());
        return solve(s, 0, mp);
    }
};
