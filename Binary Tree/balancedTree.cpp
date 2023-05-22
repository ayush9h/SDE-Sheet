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
    void solve(TreeNode* root, bool &ans, int &h)
    {
        if(root==NULL || !ans)
        {
            return;
        }
        int l=0,r=0;
        solve(root->left,ans,l);
        solve(root->right,ans,r);
        h = 1+max(l,r);

        if(abs(l-r) > 1)
        {
            ans = false;
        }
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int h = 0;
        solve(root, ans, h);
        return ans;
    }
};
