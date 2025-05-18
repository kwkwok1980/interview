// https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1?page=2&company=Goldman%20Sachs&sortBy=submissions
class Solution {
  public:
    int maximumProfit(vector<int>& prices) {
        int N = prices.size();
        int profit = 0;
        for (int i=0; i<N-1; ++i) {
            if (prices[i] < prices[i+1]) {
                profit = profit + (prices[i+1] - prices[i]);
            }
        }
        return profit;
    }
};
