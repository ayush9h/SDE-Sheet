class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0,high = n-1;
        while(low<=high)
        {
            if(nums[low]==target &&  nums[high]==target)
            {
                return {low,high};
            }
            else if(nums[low]<target)
            {
                low ++;
            }
            else{
                high--;
            }
        }   
        return {-1,-1};
    }
};
