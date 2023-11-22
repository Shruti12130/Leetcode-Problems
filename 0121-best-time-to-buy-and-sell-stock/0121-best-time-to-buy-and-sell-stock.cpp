class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0], ans = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i] > mn) {
                ans = max(ans, prices[i]-mn);
            } else {
                mn = prices[i];
            }
        }
        return ans;
    }
};