class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> output;
        std::vector<int> currSubset;

        std::sort(nums.begin(), nums.end());
        permutations(nums, 0, output);

        return output;
    }
private:
    void permutations(std::vector<int> const& nums, int pos, std::vector<std::vector<int>>& output) {
        output.push_back(nums);

        for(int i = pos; i < nums.size(); ++i) {
            auto tmp = nums;
            while (pos < nums.size()-1) {
                ++pos;
                if (tmp[i] != tmp[pos]) {
                    std::swap(tmp[i], tmp[pos]);
                    permutations(tmp, i+1, output);
                }
            }
            pos = i;
        }
    }
};
