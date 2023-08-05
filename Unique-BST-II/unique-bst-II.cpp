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
    
    vector<TreeNode*> generateBST(int start, int end) {
        vector<TreeNode*> ans;
        if(start > end) {
            ans.push_back(NULL);
            return ans;
        } 
        
        for(int i=start; i<=end; i++) {
            //These i will be the root values and the below 2 vectors
            //would store the potential subtrees for this i.
            vector<TreeNode*> leftSubtrees = generateBST(start, i-1);
            vector<TreeNode*> rightSubtrees = generateBST(i+1, end);
            
            for(int j=0; j<leftSubtrees.size(); j++) {
                for(int k=0; k<rightSubtrees.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSubtrees[j];
                    root->right = rightSubtrees[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generateBST(1, n);
    }
};
