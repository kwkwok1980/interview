//https://practice.geeksforgeeks.org/problems/non-repeating-character/0

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <memory>

int results[1000000+1]{};
int MAX = std::numeric_limits<int>::max();
int BLANK = -1;

int SolveInternal1(int V, int N, int * const coins)
{
    int& result = results[V];
    if (result != BLANK)
    {
        return result;
    }

    if (V == 0)
    {
        result = 0;
        return result;
    }

    result = MAX;
    for (int n=0; n<N; ++n)
    {
        if (coins[n] <= V)
        {
            int current = SolveInternal1(V-coins[n], N, coins);
            if (current != MAX)
            {
                result = std::min(current+1, result);
            }
        }
    }
    return result;
}

int Solve1(int V, int N, int * const coins)
{
    for(int v=0; v<V+1; ++v)
    {
        results[v] = BLANK;
    }

    SolveInternal1(V, N, coins);
    return results[V] == MAX ? -1 : results[V];
}

int Solve2(int V, int N, const int * const coins)
{
    results[0] = 0;
    for (int v=1; v<=V; ++v)
    {
        int& result = results[v] = MAX;
        for (int n=0; n<N; ++n)
        {
            if (coins[n] <= v)
            {
                int diff = v-coins[n];
                if (results[diff] != MAX)
                {
                    result = std::min(result, results[diff] + 1);
                }
            }
        }
    }
    return results[V] == MAX ? -1 : results[V];
}

int main()
{
    int T = 0;
    int V = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> V;
        std::cin >> N;
        int* coins = new int[N];
        for (int n=0; n<N; ++n)
        {
            std::cin >> coins[n];
        }
        std::cout << Solve1(V, N, coins) << std::endl;
        delete [] coins;
    }
    return 0;
}

