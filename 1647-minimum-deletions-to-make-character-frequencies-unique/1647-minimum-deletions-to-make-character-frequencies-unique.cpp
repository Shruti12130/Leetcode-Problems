class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        unordered_map<char, int> mp;
        // unordered_map<int, int> m;
        int mx=0, ans=0;
        for(int i=0;i<n;i++) {
            mp[s[i]]++;
            mx=max(mx, mp[s[i]]);
        }
        vector<int> v(mx+1, 0);
        for(auto it: mp) {
            int k=it.second;
            v[k]++;
        }
        for(int i=mx;i>0;i--) {
            if(v[i]>1) {
                int k=v[i]-1;
                ans+=k;
                v[i-1]+=k;
            }
        }
        return ans;
    }
};