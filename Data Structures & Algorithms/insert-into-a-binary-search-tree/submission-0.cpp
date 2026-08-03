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
    TreeNode* insertIntoBSTS(TreeNode* root, int val) {
        if(root==nullptr){
            return new TreeNode(val);
        }
        if(val < root->val){
           root->left =  insertIntoBSTS(root->left ,  val);
        }
        else if(val > root->val){
            root->right =insertIntoBSTS(root->right ,  val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertIntoBSTS(root,val);
    }
};