class Solution {
public:
    unordered_map<string, priority_queue<string,vector<string>,greater<string>>> graph;
    vector<string> ans;
    
    void dfs(string vertex) {
        auto &node = graph[vertex];
        //Iterate all the min heap elements for the corresponding vertex
        while(!node.empty()) {
            auto k=node.top();
            node.pop();
            dfs(k);
        }
        ans.push_back(vertex);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //Problem is about finding the Euler circuit of the graph -> 
        //Traversing each edge strictly once (while maintaining the lexical order)
        for(auto it: tickets) {
            graph[it[0]].push(it[1]);
        }
        
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};