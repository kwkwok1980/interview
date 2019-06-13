#include <iostream>
#include <array>

int SolveRecursive(const int* coins, int I, int N)
{
    if (N == 0)
    {
        return 1;
    }

    if (N < 0)
    {
        return 0;
    }

    int result = 0;
    for (int i=I; i>0; --i)
    {
        int coin = coins[i-1];
        result = result + SolveRecursive(coins, i, N - coin);
    }
    return result;
}

int SolveTable(const int* coins, int I, int N)
{
    int results[I+1][N+1];
    for (int n=0; n<=N; ++n)
    {
        results[0][n] = 0;
    }

    for (int i=1; i<=I; ++i)
    {
        results[i][0]= 1;
        for (int n=1; n<=N; ++n)
        {
            int result = results[i-1][n];
            int next = n - coins[i-1];
            if (next >= 0)
            {
                result = result + results[i][next];
            }
            results[i][n] = result;
            std::cout << i << " " << n << " " << " " << result <<std::endl;
        }
    }
    return results[I][N];
}

//https://www.geeksforgeeks.org/coin-change-dp-7/

int main() {
    std::array<int, 3> coins {1, 2, 3};
    int N = 8;
    int result1 = SolveRecursive(coins.data(), coins.size(), N);
    std::cout << result1 << std::endl;

    int result2 = SolveTable(coins.data(), coins.size(), N);
    std::cout << result2 << std::endl;
    return 0;
}
