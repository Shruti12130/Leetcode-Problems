class Solution {
public:
    unordered_map<int, multiset<int>> graph;
    vector<int> v;
    vector<vector<int>> ans;
    
    void dfs(int num) {
        auto &st=graph[num];
        while(!st.empty()) {
            int x=*st.begin();
            st.erase(st.begin());
            dfs(x);
        }
        v.push_back(num);
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> a, b;
        for(auto it: pairs) {
            graph[it[0]].insert(it[1]);
            a[it[0]]++;
            b[it[1]]++;
        }
        int k=-1;
        for(auto it: a) {
            int x=it.first;
            if(a[x]>b[x]) {
                k=x;
                break;
            }
        }
        if(k!=-1) {
            dfs(k);
        } else {
            dfs(pairs[0][0]);
        }
        
        reverse(v.begin(), v.end());
        for(int i=1;i<v.size();i++) {
            ans.push_back({v[i-1], v[i]});
        }
        return ans;
    }
};