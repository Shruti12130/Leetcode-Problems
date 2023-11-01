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
    unordered_map<int, int> mp;
    void solve(TreeNode* root) {
        if(!root) {
            return;
        }
        solve(root->left);
        mp[root->val]++;
        solve(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        solve(root);
        vector<int> ans;
        int mx=0;
        for(auto [i, j]: mp) {
            mx=max(mx, j);
        }
        for(auto [i, j]: mp) {
            if(j==mx){
                ans.push_back(i);
            }
        }
        return ans;
    }
};