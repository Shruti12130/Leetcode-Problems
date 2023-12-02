class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(auto ch: chars) {
            mp[ch]++;
        }
        int ans=0;
        for(auto word: words) {
            bool f=0;
            unordered_map<char, int> m=mp;
            for(auto ch: word) {
                if(m[ch]<=0) {
                    f=1;
                    break;
                }
                m[ch]--;
            }
            if(!f)  ans+=word.length();
        }
        return ans;
    }
};