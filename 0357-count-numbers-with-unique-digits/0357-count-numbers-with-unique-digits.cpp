class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) {
            return 1;
        }
        int ans=10;
        int uniqueDigits=9, t=9;
        for(int i=2;i<=n;i++) {
            t*=uniqueDigits;
            uniqueDigits--;
            ans+=t;
        }
        return ans;
    }
};