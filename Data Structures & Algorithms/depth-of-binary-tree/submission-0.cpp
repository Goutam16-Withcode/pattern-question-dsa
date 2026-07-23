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
    int depth(TreeNode*root){
        if(root==nullptr) return 0;
        int maxLeft = depth(root->left);
        int maxright = depth(root->right);
        return 1 + max(maxLeft , maxright);
    }
    int maxDepth(TreeNode* root) {
        int ans = depth(root);
        return ans;
    }
};
