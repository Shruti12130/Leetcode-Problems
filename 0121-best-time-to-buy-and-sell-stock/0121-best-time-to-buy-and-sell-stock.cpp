class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), ans=0;
        vector<int> maxi(n), mini(n);
        mini[0]=prices[0], maxi[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxi[i]=max(maxi[i+1], prices[i]);
        }
        ans=max(0, maxi[0]-prices[0]);
        for(int i=1;i<n;i++) {
            mini[i]=min(mini[i-1], prices[i]);
            ans=max(ans, maxi[i]-mini[i]);
        }
        return ans;
    }
};