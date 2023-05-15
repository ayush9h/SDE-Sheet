class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxPro = 0;
        for(int i=0;i<n;i++)
        {
            minPrice = min(minPrice,prices[i]);
            maxPro = max(maxPro,prices[i] - minPrice);
        }
        return maxPro;
    }
};
