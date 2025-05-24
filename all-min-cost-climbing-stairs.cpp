// https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

class Solution {
  public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int N = cost.size();
        std::vector<int> results(N+1, 0);
        results[0] = 0;
        results[1] = 0;
        for (int i=2; i<=N; ++i) {
            results[i] = std::min(results[i-1] + cost[i-1], results[i-2] + cost[i-2]);
        }
        return results[N];
    }
};
