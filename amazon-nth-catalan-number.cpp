// https://www.geeksforgeeks.org/problems/nth-catalan-number0817/1

struct Solution {
    int findCatalan(int n) {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                results[i][j] = -1;
            }
        }
        results[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            findCatalanImpl(i, i);
        }
        return results[n][n];
    }
    int findCatalanImpl(int x, int y) {
        int result = results[x][y];
        if (result != -1) {
            return result;
        }
        if (x == y) {
            result = findCatalanImpl(x-1, y);
        } else {
            result = 0;
            if (x > 0) {
                result = result + findCatalanImpl(x-1, y);
            }
            if (y > 0) {
                result = result + findCatalanImpl(x, y-1);
            }
        }
        results[x][y] = result;
        return result;
    }

    static constexpr int N = 20+1;
    int results[N][N];
};
