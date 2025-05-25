// https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

class Solution {
  public:
    bool pythagoreanTriplet(std::vector<int>& values) {
        std::unordered_set<int> results{};
        for (int value : values) {
            results.emplace(value * value);
        }
        int N = values.size();
        for (int i=0; i<N; ++i) {
            int a = values[i] * values[i];
            for (int j=i; j<N; ++j) {
                int b = values[j] * values[j];
                if (results.find(a + b) != results.end()) {
                    return true;
                }
                
            }
        }
        return false;
        
    }
};
