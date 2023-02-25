class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Set initial minimum price to be the maximum possible integer
        int maxProfit = 0;  // Set initial maximum profit to be zero
        
        // Iterate through the prices array
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {  // If the current price is less than the current minimum price,
                minPrice = prices[i];  // Update the minimum price to be the current price
            } else if (prices[i] - minPrice > maxProfit) {  // If the difference between the current price and the minimum price is greater than the current maximum profit,
                maxProfit = prices[i] - minPrice;  // Update the maximum profit to be the difference between the current price and the minimum price
            }
        }
        
        return maxProfit;  // Return the maximum profit
    }
};
