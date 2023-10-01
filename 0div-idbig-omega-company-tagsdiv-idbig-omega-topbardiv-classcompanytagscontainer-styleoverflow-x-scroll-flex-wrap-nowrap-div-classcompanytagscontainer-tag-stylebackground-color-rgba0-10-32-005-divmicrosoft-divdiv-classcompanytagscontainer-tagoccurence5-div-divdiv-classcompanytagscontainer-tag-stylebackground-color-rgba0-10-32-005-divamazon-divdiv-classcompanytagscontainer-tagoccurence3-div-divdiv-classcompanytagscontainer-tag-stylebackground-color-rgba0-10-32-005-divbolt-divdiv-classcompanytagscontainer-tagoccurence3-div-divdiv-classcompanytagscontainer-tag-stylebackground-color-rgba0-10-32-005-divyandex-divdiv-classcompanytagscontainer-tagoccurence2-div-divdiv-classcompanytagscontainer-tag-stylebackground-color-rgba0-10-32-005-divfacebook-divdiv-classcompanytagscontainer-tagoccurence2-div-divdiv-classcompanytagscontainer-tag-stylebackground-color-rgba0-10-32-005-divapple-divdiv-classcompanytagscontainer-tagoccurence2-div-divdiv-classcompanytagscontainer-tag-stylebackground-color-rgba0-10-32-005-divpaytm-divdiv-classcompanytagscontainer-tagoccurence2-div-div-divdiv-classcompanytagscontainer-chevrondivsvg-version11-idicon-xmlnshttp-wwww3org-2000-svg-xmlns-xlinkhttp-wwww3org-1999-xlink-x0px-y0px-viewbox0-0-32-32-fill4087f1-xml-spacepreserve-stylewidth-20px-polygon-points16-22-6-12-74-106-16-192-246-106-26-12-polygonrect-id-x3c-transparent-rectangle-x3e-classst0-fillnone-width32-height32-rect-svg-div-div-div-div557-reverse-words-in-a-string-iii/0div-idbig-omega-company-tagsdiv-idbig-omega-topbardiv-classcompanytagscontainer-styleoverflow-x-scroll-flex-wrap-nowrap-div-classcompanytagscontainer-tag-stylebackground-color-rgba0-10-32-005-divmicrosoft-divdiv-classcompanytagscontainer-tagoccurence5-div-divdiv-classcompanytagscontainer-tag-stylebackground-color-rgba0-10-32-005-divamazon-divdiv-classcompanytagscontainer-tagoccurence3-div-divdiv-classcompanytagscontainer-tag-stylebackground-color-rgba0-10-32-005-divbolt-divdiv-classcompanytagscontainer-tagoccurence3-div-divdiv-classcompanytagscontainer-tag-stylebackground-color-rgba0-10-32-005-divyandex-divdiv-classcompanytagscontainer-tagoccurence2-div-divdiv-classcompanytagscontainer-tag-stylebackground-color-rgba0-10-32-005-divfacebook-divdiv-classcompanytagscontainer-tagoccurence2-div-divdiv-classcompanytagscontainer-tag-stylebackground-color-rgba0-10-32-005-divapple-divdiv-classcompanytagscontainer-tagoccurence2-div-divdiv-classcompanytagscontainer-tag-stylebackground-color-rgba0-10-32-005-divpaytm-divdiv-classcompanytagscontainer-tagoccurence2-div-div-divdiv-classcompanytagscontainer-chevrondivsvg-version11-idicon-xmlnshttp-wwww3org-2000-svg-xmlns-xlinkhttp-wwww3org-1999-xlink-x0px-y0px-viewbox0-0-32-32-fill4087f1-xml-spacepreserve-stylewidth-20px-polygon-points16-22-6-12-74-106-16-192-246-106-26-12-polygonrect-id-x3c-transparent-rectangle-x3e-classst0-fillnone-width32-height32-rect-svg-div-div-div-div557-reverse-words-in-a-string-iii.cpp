class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++) {
            string temp="";
            while(i<n && s[i]!=' ') {
                temp+=s[i++];
            }
            reverse(temp.begin(), temp.end());
            ans+=(temp + " ");
        }
        ans.pop_back();
        return ans;
    }
};