// https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

class Solution {
  public:
    int MinSquares(int n) {
        results = std::vector<int>(100001, -1);
        int result = MinSquaresImpl(n);
        return result;
    }
    
    int MinSquaresImpl(int n) {
        int result = results[n];
        if (result != -1) {
            return result;
        }
        result = std::numeric_limits<int>::max();
        int K = static_cast<int>(std::sqrt(n)) ;
        for (int i=1; i<=K; ++i) {
            int a = i * i;
            int b = n - a;
            if (b > 0) {
                int c = 1 + MinSquaresImpl(b);
                result = std::min(result, c);
            } else if (b == 0) {
                result = 1;
            } else {
                break;
            }
        }
        return results[n] = result;
    }
    
    std::vector<int> results;
};
