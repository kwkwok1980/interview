// https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
class Solution {
  public:
    int maxProduct(std::vector<int>& values) {
        int N = values.size();
        std::vector<int> minResults(N, 0);
        std::vector<int> maxResults(N, 0);
        for (int i=0; i<N; ++i) {
            int value = values[i];
            if (i == 0) {
                minResults[i] = value;
                maxResults[i] = value;
            } else {
                int min = value;
                min = std::min(min, value * minResults[i-1]);
                min = std::min(min, value * maxResults[i-1]);
                minResults[i] = min;
                int max = value;
                max = std::max(max, value * minResults[i-1]);
                max = std::max(max, value * maxResults[i-1]);
                maxResults[i] = max;
            }
        }
        
        int result = std::numeric_limits<int>::min();
        for (int i=0; i<N; ++i) {
            result = std::max(result, maxResults[i]);
        }
        return result;
    }
};
