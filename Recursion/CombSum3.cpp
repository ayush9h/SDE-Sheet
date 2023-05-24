class Solution {
public:
    void generateCombo(int ind, int k, int n,vector<vector<int>> &ans, vector<int> &ds)
    {
        if(!k || !n)
        {
            if(!k && !n) ans.push_back(ds);
            return;
        }

        for(int i = ind;i<=9;i++)
        {
            if(n<i) return;

            ds.push_back(i);
            generateCombo(i+1,k-1,n-i,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        generateCombo(1,k,n,ans,ds);
        return ans;
    }
};
