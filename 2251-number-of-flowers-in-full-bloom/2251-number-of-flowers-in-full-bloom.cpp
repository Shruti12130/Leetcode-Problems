class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=people.size();
        vector<int> ans(n), start, end;
        
        for(int i=0;i<flowers.size();i++) {
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        for(int t=0;t<n;t++) {
            int num1=upper_bound(start.begin(), start.end(), people[t])-start.begin();
            int num2=lower_bound(end.begin(), end.end(), people[t])-end.begin();
            //cout<<num1<<" "<<num2<<endl;
            ans[t] = (num1-num2);
        }
        return ans;
    }
};