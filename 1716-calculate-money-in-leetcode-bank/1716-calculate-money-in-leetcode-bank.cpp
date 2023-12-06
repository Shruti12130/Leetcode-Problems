class Solution {
public:
    int totalMoney(int n) {
        int initial=1, day=0, ans=0, curr=1, c=0;
        while(day<n) {
            if(c==7) {
                initial++;
                curr=initial;
                c=0;
            }
            ans+=curr;
            curr++;
            c++;
            day++;
        }
        return ans;
    }
};