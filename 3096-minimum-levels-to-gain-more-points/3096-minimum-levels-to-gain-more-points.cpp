class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=size(possible);
        for(int i=0;i<n;i++) {
            if(possible[i]==0) {
                possible[i]=-1;
            }
        }
        int total=accumulate(possible.begin(), possible.end(), 0), sum=0;
        for(int i=0;i<n-1;i++) {
            sum+=possible[i];
            if(sum>total-sum) {
                return i+1;
            }
        }
        return -1;
    }
};