class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        int mp[n+1][26];
        memset(mp, 0, sizeof mp);
        
        vector<string> ans;
        
        for(int i=0;i<n;i++) {
            string word=words[i];
            for(auto letter: word) {
                mp[i][letter-'a']++;
            }
        }
        
        for(int j=0;j<26;j++) {
            int mn=1e9;
            for(int i=0;i<n;i++) {
                mn=min(mn, mp[i][j]);
                if(!mp[i][j]) {
                    break;
                }
            }
            int num=mn;
            char ch=j+'a';
            while(num--) {
                ans.push_back(string(1, ch));
            }
        }
        
        return ans;
    }
};