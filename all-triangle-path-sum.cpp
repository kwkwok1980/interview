// https://www.geeksforgeeks.org/problems/triangle-path-sum/1

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& triangle) {
        int N = triangle.size();
        int results[200][200]{};
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                results[i][j] = std::numeric_limits<int>::max();
            }
        }
        results[0][0] = triangle[0][0];
        for (int i=1; i<N; ++i) {
            for (int j=0; j<=i; ++j) {
                if (j == 0) {
                    results[i][j] = results[i-1][j] + triangle[i][j]; 
                } else if (j == i) {
                    results[i][j] = results[i-1][j-1] + triangle[i][j];
                } else {
                    results[i][j] = std::min(results[i-1][j-1] + triangle[i][j],  results[i-1][j] + triangle[i][j]);
                }
            }
        }
        int result = std::numeric_limits<int>::max();
        for (int i=0; i<N; ++i) {
            result = std::min(result, results[N-1][i]);
        }
        return result;
    }
};
