class Solution {
   public:
    TreeNode* applied(vector<int>& preorder, int prestart, int prend, vector<int>& inorder,
                      int instart, int inend, unordered_map<int, int>& mp) {
        if (prestart > prend || instart > inend) return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int mroot = mp[root->val];
        int numsleft = mroot - instart;

        root->left =
            applied(preorder, prestart + 1, prestart + numsleft, inorder, instart, mroot - 1, mp);

        root->right =
            applied(preorder, prestart + numsleft + 1, prend, inorder, mroot + 1, inend, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        return applied(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }
};