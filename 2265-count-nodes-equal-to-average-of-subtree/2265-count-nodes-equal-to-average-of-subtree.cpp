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
    
    pair<int, int> solve(TreeNode* root, int &ans, int sum, int val) {
        if(!root) {
            return {0, 0};
        }
        auto leftVal = solve(root->left, ans, sum, val);
        auto rightVal = solve(root->right, ans, sum, val);
        sum = root->val+leftVal.first+rightVal.first;
        val = 1+leftVal.second+rightVal.second;
        if(root->val==sum/val) {
            ans++;
        }
        return {sum, val};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(root, ans, 0, 0);
        return ans;
    }
};