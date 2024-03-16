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
    
    int solve(TreeNode* root, int &mx) {
        if(!root) {
            return 0;
        }
        
        int l=max(solve(root->left, mx), 0);
        int r=max(solve(root->right, mx), 0);
        int sum=l+r+root->val;
        mx=max(mx, sum);
        return root->val+max(l, r);
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            return root->val;
        }
        int mx=INT_MIN;
        solve(root, mx);
        return mx;
    }
};