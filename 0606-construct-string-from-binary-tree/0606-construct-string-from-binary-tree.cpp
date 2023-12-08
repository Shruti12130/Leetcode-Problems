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
    string ans="";
    
    void preorder(TreeNode* root) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            ans+="("+to_string(root->val)+")";
            return;
        }
        
        ans+=("("+to_string(root->val));
        if(root->left)
            preorder(root->left);
        else
            ans+="()";
        preorder(root->right);  
        ans+=")";
    }
    
    string tree2str(TreeNode* root) {
        if(!root){
            return ans;
        }
        preorder(root);
        return ans.substr(1, ans.length()-2);
    }
};