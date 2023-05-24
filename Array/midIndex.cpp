class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        int rightSum = 0,leftSum = 0;

        for(auto i:nums)
        {
            totalSum+=i;
        }

        for(int i=0;i<nums.size();i++)
        {
            rightSum = totalSum - leftSum - nums[i];
            if(rightSum == leftSum)
            {
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};
