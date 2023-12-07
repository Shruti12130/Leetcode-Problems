class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int k=0, f=0;
        for(int i=num.length()-1;i>=0;i--) {
            int digit=num[i]-'0';
            if(digit%2==0) {
                continue;
            } else {
                f=1;
                k=i+1;
                break;
            }
        }
        if(f) {
            ans=num.substr(0, k);
        }
        return ans;
    }
};