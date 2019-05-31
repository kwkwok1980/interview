//https://practice.geeksforgeeks.org/problems/coin-change/0

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

static const int MAX = 300;
static int results[MAX+1][MAX+1];
static int coins[MAX];

int SolveInternal(int M, int N, int A)
{
    if (N == 0)
    {
        results[N][A] = 0;
        return results[N][A];
    }

    int count =  0;
    for (int m=0; m<M; ++m)
    {
        int coin = coins[m];
        if (coin >= A)
        {
            if (N == coin)
            {
                ++count;
            }
            else if (N > coin)
            {
                count += results[N-coin][coin];
            }
            else
            {
                break;
            }
        }
    }

    results[N][A] = count;
    return results[N][A];
}

void Solve(int M, int N)
{
    std::sort(coins, coins+M);
    for (int n=0; n<=N; ++n)
    {
        for (int m=0; m<M; ++m)
        {
            SolveInternal(M, n, coins[m]);
        }
    }

    std::cout << results[N][coins[0]] << std::endl;
}

int main()
{
    int T = 0;
    int M = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> M;
        for (int m=0; m<M; ++m)
        {
            std::cin >> coins[m];
        }
        std::cin >> N;
        Solve(M, N);
    }
    return 0;
}
