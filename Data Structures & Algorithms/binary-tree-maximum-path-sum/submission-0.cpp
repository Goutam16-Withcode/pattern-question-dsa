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
    int maximumW(TreeNode*root,int &maxi){
        if(root==nullptr) return 0;
        int left = max(maximumW(root->left,maxi),0);
        int right = max(maximumW(root->right,maxi),0);

        int through = root->val + left + right;
        maxi = max(maxi,through);
        return root->val + max(left,right); 
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maximumW(root,maxi);
        return maxi;
    }
};
