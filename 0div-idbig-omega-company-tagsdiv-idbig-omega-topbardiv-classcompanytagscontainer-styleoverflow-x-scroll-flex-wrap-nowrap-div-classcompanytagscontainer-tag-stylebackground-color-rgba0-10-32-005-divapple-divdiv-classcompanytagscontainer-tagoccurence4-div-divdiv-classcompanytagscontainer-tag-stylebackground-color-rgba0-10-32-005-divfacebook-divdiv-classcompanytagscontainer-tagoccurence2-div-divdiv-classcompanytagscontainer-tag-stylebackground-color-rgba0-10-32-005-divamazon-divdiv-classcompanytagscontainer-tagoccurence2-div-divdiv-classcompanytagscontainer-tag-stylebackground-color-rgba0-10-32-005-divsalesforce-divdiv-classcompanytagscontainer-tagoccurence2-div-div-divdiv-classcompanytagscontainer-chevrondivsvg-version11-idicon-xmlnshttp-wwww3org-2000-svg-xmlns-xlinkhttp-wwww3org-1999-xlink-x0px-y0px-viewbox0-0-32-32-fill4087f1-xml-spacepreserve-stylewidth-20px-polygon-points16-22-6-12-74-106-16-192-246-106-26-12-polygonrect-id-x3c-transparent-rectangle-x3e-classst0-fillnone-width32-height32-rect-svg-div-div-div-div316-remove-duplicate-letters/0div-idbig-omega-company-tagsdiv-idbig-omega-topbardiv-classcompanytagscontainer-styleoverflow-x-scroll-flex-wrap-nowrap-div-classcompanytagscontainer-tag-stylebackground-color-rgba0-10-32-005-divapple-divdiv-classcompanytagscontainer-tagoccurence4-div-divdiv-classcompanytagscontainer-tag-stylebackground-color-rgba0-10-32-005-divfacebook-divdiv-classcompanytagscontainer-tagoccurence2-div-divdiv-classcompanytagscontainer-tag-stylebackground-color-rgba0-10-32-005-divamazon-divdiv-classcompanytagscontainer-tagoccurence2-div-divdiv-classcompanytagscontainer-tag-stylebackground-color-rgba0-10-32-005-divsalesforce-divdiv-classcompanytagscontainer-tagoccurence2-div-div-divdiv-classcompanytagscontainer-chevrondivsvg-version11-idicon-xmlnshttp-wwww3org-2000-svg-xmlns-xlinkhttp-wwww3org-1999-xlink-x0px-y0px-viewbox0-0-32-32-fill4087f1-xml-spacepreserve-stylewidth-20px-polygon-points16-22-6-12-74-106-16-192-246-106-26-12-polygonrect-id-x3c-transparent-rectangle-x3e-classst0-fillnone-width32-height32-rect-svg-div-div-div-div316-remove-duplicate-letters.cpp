class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        vector<int> v(26, 0);
        vector<bool> vis(26, false);
        for(int i=0;i<n;i++) {
            v[s[i]-'a']++;
        }
        string ans="";
        for(char c: s) {
            v[c-'a']--;
            if(ans.size()==0) {
                ans+=c;
                vis[c-'a']=true;
                continue;
            }
            if(vis[c-'a']) {
                continue;
            }
            while(ans.size()>0 && c<=ans.back() && v[ans.back()-'a']) {
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans+=c;
            vis[c-'a']=true;
        }
        return ans;
    }
};