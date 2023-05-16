class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
           set<vector<int>> s;
        vector<vector<int>> ans;
        
        if (nums.size()<4) {
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i=0; i<n-3; i++) {
            for (int j=i+1; j<n-2; j++) {
                int low = j+1;
                int high = n-1;
                
                while (low<high) {
                  long long sum = (long long)nums[i] + nums[j] + nums[low] + nums[high];                    
                    if (sum == target) {
                        s.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                    else if (sum<target) {
                        low++;
                    }
                    else {
                        high--;
                    }
                }
            }
        }
        
        for (auto x : s) {
            ans.push_back(x);
        }
        
        return ans;
    }
};
