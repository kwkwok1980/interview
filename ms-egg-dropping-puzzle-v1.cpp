// https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

class Solution {
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int N, int K) {
        int results[1001][1001]{};
        for (int k=1; k<=K; ++k) {
            for (int n=1; n<=N; ++n) {
                int result = std::numeric_limits<int>::max();
                if (n == 1) {
                    result = k;
                } else {
                    for (int l=1; l<=k; ++l) {
                        result = std::min(result, 1 + std::max(results[n-1][l-1], results[n][k-l]));
                    }
                }
                results[n][k] = result;
            }
        }
        return results[N][K];
    }
    
    
};
