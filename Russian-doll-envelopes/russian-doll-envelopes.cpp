class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(i==0 || ans[ans.size() - 1] < envelopes[i][1]) {
                ans.push_back(envelopes[i][1]);
            } else {
                // auto it = lower_bound(ans.begin(), ans.end(), envelopes[i][1]);
                // *it = envelopes[i][1];
                
                //By binary search algo: 
                int left = 0; 
                int right = ans.size()-1;
                int res = left;
                while(left <= right) {
                    int mid = left + (right-left)/2;
                    if (ans[mid] >= envelopes[i][1]) {
                        res = mid;
                        right = mid-1;
                    } else { // tail[mid] < n
                        left = mid+1;
                    }
                }
                ans[res] = envelopes[i][1];
            }
        }
        return ans.size();
    }
};
