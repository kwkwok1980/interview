//https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

void Solve(int (&matrix)[30][30], int N, int M, int X) {
    for (int n=0; n<N; ++n)
    {
        if (matrix[n][0] <= X && (n==N-1 || matrix[n+1][0] > X))
        {
            for (int m=0; m<M && matrix[n][m] <=X; ++m)
            {
                if (matrix[n][m] == X)
                {
                    std::cout << 1 << std::endl;
                    return;
                }
            }
            std::cout << 0 << std::endl;
            return;
        }
    }
    std::cout << 0 << std::endl;
}

int main() {
    int T = 0;
    int N = 0;
    int M = 0;
    int X = 0;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::cin >> N;
        std::cin >> M;
        int matrix[30][30];
        for (int n=0; n<N; ++n)
        {
            for (int m=0; m<M; ++m)
            {
                std::cin >> matrix[n][m];
            }
        }
        std::cin >> X;
        Solve(matrix, N, M, X);
    }
}
