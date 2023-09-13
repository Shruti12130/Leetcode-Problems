class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(n, 1);
        
        for(int i=1;i<n;i++) {
            if(ratings[i]>ratings[i-1]) {
                candies[i]=1+candies[i-1];
            }
        }
        for(int i=n-2;i>=0;i--) {
            if(ratings[i]>ratings[i+1]) {
                candies[i]=max(candies[i], 1+candies[i+1]);
            }
        }
        //for(auto it: candies) cout<<it<<" ";cout<<endl;
        return accumulate(candies.begin(), candies.end(), 0);
    }
};