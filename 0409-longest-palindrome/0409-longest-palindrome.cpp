class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        int ans=0, c=0;
        for(auto it: mp) {
            if(it.second%2==1) {
                c=1;
            }
            int k=it.second;
            ans+=(k%2==0 ? k : k-1);
        }
        if(c) {
            ans++;
        }
        return ans;
    }
};