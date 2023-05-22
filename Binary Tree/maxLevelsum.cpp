class Solution {
public:

    int maxLevelSum(TreeNode* root) {
        
        int sum = INT_MIN;

        int level = 1;
        int res = 0;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            int val = 0;
            int n = q.size();
            
            for(int i = 0; i < n; ++i)
            {

            auto temp = q.front();
            q.pop();
            
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);

            val+=temp->val;
        
            }

            if(sum < val)
            {
                sum = val;
                res = level;
            }

            level++;

        }

        return res;
    }
};
