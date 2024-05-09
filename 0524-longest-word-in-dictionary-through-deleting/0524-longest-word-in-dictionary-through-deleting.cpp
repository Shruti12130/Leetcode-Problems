class Solution {
public:
    
    bool isSubsequence(string &s, string &x) {
        int c=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]==x[c]) {
                c++;
            }
        }
        return (c==x.length());
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        if(dictionary.size()==0 || s.empty()) {
            return "";
        }
        
        sort(dictionary.begin(), dictionary.end(), [&](auto &a, auto &b){
            if(a.length()==b.length()) {
                return a>b;
            }
            return a.length() < b.length();
        });
        for(int i=dictionary.size()-1;i>=0;i--) {
            if(isSubsequence(s, dictionary[i])) {
                return dictionary[i];
            }
        }
        return "";
    }
};