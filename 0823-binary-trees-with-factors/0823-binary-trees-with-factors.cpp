class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size(), mod=1e9+7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> mp;
        
        for(int i=0;i<n;i++) {
            long count=1;
            for(int j=0;j<i;j++) {
                if(arr[i]%arr[j]==0) {
                    count+= mp[arr[j]] * mp[arr[i]/arr[j]]%mod;
                }
            }
            mp[arr[i]]=count;
        }
        long ans=0;
        for(auto [i, j]: mp) {
            (ans+=j)%=mod;
        }
        return ans;
    }
};