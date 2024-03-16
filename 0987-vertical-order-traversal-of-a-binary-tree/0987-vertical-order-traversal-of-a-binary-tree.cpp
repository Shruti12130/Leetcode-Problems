/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        map<int, map<int, multiset<int>>> mp;   
        queue<pair<TreeNode*, pair<int, int>>> q;   //{node, {line, level}}
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto k=q.front();
            q.pop();
            
            auto node=k.first;
            int line=k.second.first, level=k.second.second;
            
            mp[line][level].insert(node->val);
            
            if(node->left)
                q.push({node->left, {line-1, level+1}});
            if(node->right)
                q.push({node->right, {line+1, level+1}});
        }
        
        for(auto it: mp){
            vector<int> col;
            for(auto itr: it.second){
                col.insert(col.end(), itr.second.begin(), itr.second.end());  //for every col, insert all the levels
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};