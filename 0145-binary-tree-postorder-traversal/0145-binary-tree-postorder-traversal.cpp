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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> tree;
        if(!root) {
            return tree;
        }
        stack<TreeNode*> st, ans;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            ans.push(temp);
            if(temp->left) {
                st.push(temp->left); 
            }
            if(temp->right) {
                st.push(temp->right); 
            }
        }
        while(!ans.empty()){
            tree.push_back(ans.top()->val);
            ans.pop();
        }
        return tree;
    }
};