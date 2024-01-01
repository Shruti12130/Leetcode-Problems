class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // vector<bool> vis(30001, false);
        sort(s.begin(), s.end());
        int ans=0;
        for(int i=0;i<g.size();i++) {
            int pos = upper_bound(s.begin(), s.end(), g[i]-1) - s.begin();
            //cout<<g[i]<<" -> "<<pos<<endl;
            if(pos<s.size() && s[pos]>=g[i]) {
                ans++;
                // vis[pos]=1;
                s.erase(s.begin()+pos);
            }
        }
        return ans;
    }
};