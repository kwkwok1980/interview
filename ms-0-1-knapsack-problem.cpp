//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

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
#include <fstream>
#include <queue>


void Solve(int N, int W, int values[], int weights[])
{
    int results[N+1][W+1];
    for (int n=0; n<=N; ++n)
    {
        for (int w=0; w<=W; ++w)
        {
            if (n == 0)
            {
                results[n][w] = 0;
            }
            else if (w == 0)
            {
                results[n][w] = 0;
            }
            else
            {
                if (w >= weights[n-1])
                {
                    results[n][w] = std::max(results[n-1][w], values[n-1] + results[n-1][w - weights[n-1]]);
                }
                else
                {
                    results[n][w] = results[n-1][w];
                }
            }

            //std::cout << n << " " << w << " " << results[n][w] << std::endl;
        }
    }
    std::cout << results[N][W] << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;
    int W = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::cin >> W;

        int values[N];
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }

        int weights[N];
        for (int n=0; n<N; ++n)
        {
            std::cin >> weights[n];
        }

        Solve(N, W, values, weights);
    }
    return 0;
}
