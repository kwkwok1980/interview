// https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

class Solution {
  public:
    int eggDrop(int N, int K) {
        std::vector<std::vector<int>> dp(N+1,vector<int>(K+1,-1));
        return solve(N, K, dp);
    }
    
    int solve(int N, int K, std::vector<std::vector<int>>& dp) {
        if(N == 1) {
            return K;
        }
        if(K == 1) {
            return 1;
        }
        if(dp[N][K] != -1) {
            return dp[N][K];
        }
        int result = std::numeric_limits<int>::max();
        for(int k=1 ; k<=K; ++k) {
            if (k == 1) {
                result = std::min(result, 1 + solve(N, K-k, dp));    
            } else if (k == K) {
                result = std::min(result, 1 + solve(N-1, k-1, dp));
            } else {
                result = std::min(result, 1 + std::max(solve(N-1, k-1, dp), solve(N, K-k, dp)));    
            }
        }
        return dp[N][K]= result;
    }
    
    
};
