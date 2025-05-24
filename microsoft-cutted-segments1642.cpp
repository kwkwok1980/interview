// https://www.geeksforgeeks.org/problems/cutted-segments1642/1

class Solution {
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        results = std::vector<int>(10000 + 1, std::numeric_limits<int>::min());
        int result = maximizeTheCutsImpl(n, x, y, z);
        return result != -1 ? result : 0;
    }

    int maximizeTheCutsImpl(int n, int x, int y, int z) {
        if (n == 0) {
            return 0;
        }
        if (n < 0) {
            return -1;
        }
        int result = results[n];
        if (result != std::numeric_limits<int>::min()){
            return result;
        }
        result = -1;
        int result_x = maximizeTheCutsImpl(n-x, x, y, z);
        if (result_x != -1) {
            result = std::max(result, 1 + result_x);
        }
        int result_y = maximizeTheCutsImpl(n-y, x, y, z);
        if (result_y != -1) {
            result = std::max(result, 1 + result_y);
        }
        int result_z = maximizeTheCutsImpl(n-z, x, y, z);
        if (result_z != -1) {
            result = std::max(result, 1 + result_z);
        }
        return results[n] = result;
    }
    std::vector<int> results{};
};
