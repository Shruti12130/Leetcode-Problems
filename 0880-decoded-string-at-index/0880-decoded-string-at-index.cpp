class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n=s.length(), i=0;
        long long lengthOfDecodedString = 0;
        while(lengthOfDecodedString < k) {
            if(s[i]>='2' && s[i]<='9') {
                lengthOfDecodedString *= (s[i]-'0');
            } else {
                lengthOfDecodedString++;
            }
            i++;
        }
        
        string ans="";
        for(int j=i-1;j>=0;j--) {
            if(s[j]>='2' && s[j]<='9') {
                lengthOfDecodedString /= (s[j]-'0');
                k %= lengthOfDecodedString;
            } else {
                if(k==0 || k==lengthOfDecodedString) {
                    ans+=s[j];
                    return ans;
                }
                lengthOfDecodedString--;
            }
        }
        return "";
    }
};