class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size();
        int ans=0;
        vector<int> temp;
        for(int i=1;i<n;i++) {
            temp.clear();
            if(colors[i]!=colors[i-1]) {
                continue;
            } else {
                temp.push_back(neededTime[i-1]);
                while(i<n && colors[i]==colors[i-1]) {
                    temp.push_back(neededTime[i]);
                    i++;
                }
                ans+=(accumulate(temp.begin(), temp.end(), 0) - 
                      *max_element(temp.begin(), temp.end()));
                i--;
            }
        }
        return ans;
    }
};