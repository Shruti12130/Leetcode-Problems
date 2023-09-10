class Solution {
public:
    int mod=1e9+7;
    int countOrders(int n) {
        long long ans=1;
        for(int i=1;i<=n;i++) {
            ans*=i;
            ans%=mod;
        }
        for(int i=1;i<2*n;i+=2) {
            ans*=i;
            ans%=mod;
        }
        return (int)ans;
    }
};