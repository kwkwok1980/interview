// https://www.geeksforgeeks.org/problems/number-of-coins1824/1

class Solution {
  public:
    int minCoins(std::vector<int>& coins, int sum) {
        int N = coins.size();
        std::vector<int> results(sum + 1, 0);
        results[0] = 0;
        for (int i=1; i<=sum; ++i) {
            int result = -1;
            for (int j=0; j<N; ++j) {
                int coin = coins[j];
                int change = i - coin;
                if (change == 0) {
                    result = 1;
                } else if (change > 0) {
                    if (results[change] != -1) {
                        if (result != -1) {
                            result = std::min(result, results[change] + 1);    
                        } else {
                            result = results[change] + 1;    
                        }
                    }    
                }
            }
            results[i] = result;
        }
        return results[sum];
    }
};
