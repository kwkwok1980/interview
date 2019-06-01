//https://practice.geeksforgeeks.org/problems/count-the-numbers/0

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <memory>
#include <unordered_map>
#include <sstream>

int matrix[10][10];

void Solve(int M, int N)
{
    int n = 0;
    int m = 0;
    while (M>0 && N>0)
    {
        for (int i=n; i<n+N; ++i)
        {
            std::cout << matrix[m][i] << " ";
        }

        for (int i=m+1; i<m+M; ++i)
        {
            std::cout << matrix[i][n+N-1] << " ";
        }

        if (M > 1)
        {
            for (int i=n+N-2; i>=n; --i)
            {
                std::cout << matrix[m+M-1][i] << " ";
            }
        }

        if (N > 1)
        {
            for (int i=m+M-2; i>=m+1; --i)
            {
                std::cout << matrix[i][n] << " ";
            }
        }

        m += 1;
        n += 1;
        M -= 2;
        N -= 2;
    }
    std::cout << std::endl;
}

int main()
{
    int T = 0;
    int M, N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> M;
        std::cin >> N;
        for (int m=0; m<M; ++m)
        {
            for (int n=0; n<N; ++n)
            {
                std::cin >> matrix[m][n];
            }
        }
        Solve(M, N);
  }
    return 0;
}
