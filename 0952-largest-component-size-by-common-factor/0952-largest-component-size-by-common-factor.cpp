class Solution {
public:
    vector<int> rank, parent;
    int findParent(int node) {
        if(node == parent[node]) {
            return parent[node];
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void Union(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if(u == v) {
            return;
        }
        
        if(rank[u] < rank[v]) {
            parent[u] = v;
        } else if(rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[u] = v;
            rank[v]++;
        }
    }
    
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        int m = *max_element(nums.begin(), nums.end());
        rank.resize(m+1);
        parent.resize(m+1);
        iota(parent.begin(), parent.end(), 0);
        
        for(auto it: nums) {
            for(int i=2;i<=sqrt(it);i++) {
                if(it%i==0) {
                    Union(it, i);
                    Union(it, it/i);
                }
            }
        }
        int ans=1;
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;i++) {
            ans = max(ans, ++mp[findParent(nums[i])]);
        }
        return ans;
        
    }
};