class Solution {
private:
    map<int, int> m;

    TreeNode* helper(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (ps > pe || is > ie || ps >= preorder.size() || pe >= preorder.size() || ps < 0 || pe < 0) {
            return NULL;
        }

        TreeNode* newNode = new TreeNode(preorder[ps]);

        int inorder_index = m[preorder[ps]];
        int left_size = inorder_index - is;
        

        TreeNode* left = helper(preorder, ps + 1, ps + left_size, inorder, is, inorder_index - 1);
        TreeNode* right = helper(preorder, ps + left_size + 1, pe, inorder, inorder_index + 1, ie);

        newNode->left = left;
        newNode->right = right;
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if (n == 0) return NULL;
        for (int i = 0; i < n; ++i) {
            m[inorder[i]] = i;
        }
        return helper(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};
