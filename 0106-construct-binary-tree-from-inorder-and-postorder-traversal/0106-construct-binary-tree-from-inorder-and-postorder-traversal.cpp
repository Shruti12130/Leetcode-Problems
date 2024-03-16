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
    int findRootIndex(vector<int> &in, int key) {
        for(int i=0;i<in.size();i++) {
            if(in[i] == key) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* buildTree(vector<int> &post, vector<int> &in, int &ind, int start, int end) {
        if(start > end) {
            return NULL;
        }
        int idx = findRootIndex(in, post[ind]);

        TreeNode* root = new TreeNode(post[ind--]);
        root->right = buildTree(post, in, ind, idx+1, end);
        root->left = buildTree(post, in, ind, start, idx-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind = inorder.size()-1;
        return buildTree(postorder, inorder, ind, 0, inorder.size()-1);
    }
    
    
    
};