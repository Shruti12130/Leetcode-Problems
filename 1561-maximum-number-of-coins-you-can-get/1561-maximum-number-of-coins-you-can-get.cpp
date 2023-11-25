class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.begin(), piles.end());
        int k=n/3, x=n-1, ans=0;
        while(k--) {
            ans+=(piles[--x]);
            x--;
        }
        return ans;
    }
};