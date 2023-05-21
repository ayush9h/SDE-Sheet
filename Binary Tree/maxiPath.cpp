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

    int ans = INT_MIN;
    int solve(TreeNode * root)
    {
        if(root==NULL)
            return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        int path = root->val;
        path = max(path,path+left);
        path = max(path,path+right);

        //store the ans
        ans = max(ans,path);

        // return max(current node, left subtree, right subtree);
        return max(root->val,root->val+max(left,right));        
    }

    int maxPathSum(TreeNode* root) {
        ans = root->val;
        solve(root);
        return ans;
    }
};
