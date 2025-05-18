// https://www.geeksforgeeks.org/problems/buy-stock-2/1?page=3&company=Goldman%20Sachs&sortBy=submissions

class Solution {
  public:
    int maximumProfit(std::vector<int> &prices) {
        int min = prices[0];
        int max = prices[0];
        int profit = 0;
        int N = prices.size();
        for (int i=1; i<N; ++i) {
            int price = prices[i];
            if (price < min) {
                profit = std::max(profit, (max - min));
                min = price;
                max = price;
            } else {
              if (price > max) {
                  max = price;
              }
            }
        }
        profit = std::max(profit, (max-min));
        return profit;
    }
};
