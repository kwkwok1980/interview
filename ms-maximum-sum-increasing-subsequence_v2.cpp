// https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution {
  public:
    int maxSumIS(std::vector<int>& values) {
        int N = values.size();
        std::vector<int> results(N, 0);
        results[N-1] = values[N-1];
        for (int i=N-2; i>=0; --i) {
            int value = values[i];
            int result = value;
            for (int j=i+1; j<N; ++j) {
                if (value < values[j]) {
                    result = std::max(result, results[j] + value);
                }
            }
            results[i] = result;
        }
        return *std::max_element(results.begin(), results.end());
    }
};
