// https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

class Solution {
  public:
    int maxProfit(std::vector<int>& prices) {
        int N = prices.size();
        std::vector<int> delta(N, 0);
        for (int i=1; i<N; ++i) {
            delta[i] = prices[i] - prices[i-1];
        }
    
        std::vector<int> toRight(N, 0);
        for (int i=1; i<N; ++i) {
            toRight[i] = std::max(delta[i], toRight[i-1] + delta[i]);
        }
        
        std::vector<int> toLeft(N, 0);
        toLeft[N-1] = delta[N-1];
        for (int i=N-2; i>=0; --i) {
            toLeft[i] = std::max(delta[i], toLeft[i+1] + delta[i]);
        }
        
        std::vector<int> toRightMax(N, 0);
        for (int i=1; i<N; ++i) {
            toRightMax[i] = std::max(toRightMax[i-1], toRight[i]);
        }
        
        std::vector<int> toLeftMax(N, 0);
        toLeftMax[N-1] = std::max(0, toLeft[N-1]);
        for (int i=N-2; i>=0; --i) {
            toLeftMax[i] = std::max(toLeftMax[i+1], toLeft[i]);
        }
        
        int profit = 0;
        for (int i=0; i<N; ++i) {
            if (i == N-1) {
                profit = std::max(profit, toRightMax[i]);
            } else {
                profit = std::max(profit, toRightMax[i] + toLeftMax[i+1]);
            }
        }
        return profit;
    }

};
