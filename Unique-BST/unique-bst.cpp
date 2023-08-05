class Solution {
public:
   int numTrees(int n) {
        //Catalan number
        //C0=1; Cn=sum(Ci*C(n-i-1))
        int dp[n+1];
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=n;i++) {
            dp[i]=0;
            for(int j=1;j<=i;j++) {
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
