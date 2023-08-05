class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st{bank.begin(), bank.end()};
        
        queue<string> q;
        q.push(startGene);
        
        if(st.find(endGene) == st.end()) {
            return -1;
        }
        
        vector<char> characters = {'A', 'C', 'G', 'T'};
        int ans = 0;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string gene = q.front();
                q.pop();
                if(gene == endGene) {
                    return ans;
                }
                
                for(int i=0;i<8;i++) {
                    for(auto it: characters) {
                        string newGene = gene;
                        newGene[i] = it;
                        if(st.count(newGene)) {
                            q.push(newGene);
                            //to mark it visited,i.e., since this gene is visited this
                            //is no longer a valid gene to visit twice
                            st.erase(newGene);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
