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
    int remove(TreeNode* root)
    {
        if(root==NULL) return 0;

        int l =remove(root->left);
        int r = remove(root->right);

        if(l==0) root->left = NULL;
        if(r==0) root->right = NULL;

        return max(l|r, root->val);
    }
    TreeNode* pruneTree(TreeNode* root) {
       remove(root);
       if(root->left== NULL && root->right== NULL && root->val == 0) return NULL;

       return root;
    }
};
