// https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

class Solution {
  public:
    int countWays(int n) {
        std::vector<int> results(n+1 ,0);
        results[1] = 1;
        results[2] = 2;
        for (int i=3; i<=n; ++i) {
            results[i] = results[i-1] + results[i-2];
        }
        return results[n];
    }
};
