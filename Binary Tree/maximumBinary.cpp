class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for(int i=0;i<nums.size();i++)
        {
            TreeNode* curr = new TreeNode(nums[i]);
            while(!stk.empty() && stk.back()->val<nums[i])
            {
                curr->left = stk.back();
                stk.pop_back();
            }
            if(!stk.empty())
                stk.back()->right = curr;
            stk.push_back(curr);
        }
        return stk.front();
    }
};
