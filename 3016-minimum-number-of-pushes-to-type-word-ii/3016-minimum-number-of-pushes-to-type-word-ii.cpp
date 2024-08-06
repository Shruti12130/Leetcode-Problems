class Solution {
public:
    int minimumPushes(string word) {
        vector<int> ch(26, 0);
        for(int i=0;i<word.length();i++) {
            ch[word[i]-'a']++;
        }
        sort(ch.rbegin(), ch.rend());
        int ans=0;
        for(int i=0;i<26;i++) {
            if(i<8) {
                ans+=ch[i];
            } else if(i>=8 && i<16) {
                ans+=(2*ch[i]);
            } else if(i>=16 && i<24) {
                ans+=(3*ch[i]);
            } else {
                ans+=(4*ch[i]);
            }
        }
        return ans;
    }
};