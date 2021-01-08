//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

int results[10+1][50+1]{};

int eggDropInternal(const int N, const int K)
{
    if (results[N][K] != -1)
    {
        return results[N][K];
    }

    if (K == 1)
    {
        results[N][K] = 1;
        return results[N][K];
    }

    if (N == 1)
    {
        results[N][K] = K;
        return results[N][K];
    }

    int result = std::numeric_limits<int>::max();
    for (int k=1; k<=K; ++k)
    {
        if (k == 1)
        {
            result = std::min(result, 1 + eggDropInternal(N, K-k));
        }
        else if (k == K)
        {
            result = std::min(result, 1 + eggDropInternal(N-1, k-1));
        }
        else
        {
            result = std::min(result, 1 + std::max(eggDropInternal(N, K-k), eggDropInternal(N-1, k-1)));
        }
    }

    results[N][K] = result;
    return results[N][K];
}

int eggDrop (int N, int K)
{
    for (int n=1; n<=10; ++n)
    {
        for (int k=1; k<=50; ++k)
        {
            results[n][k] = -1;
        }
    }
    return eggDropInternal(N, K);
}

int main()
{
    std::cout << eggDrop(2, 10) << std::endl;
    std::cout << eggDrop(3, 5) << std::endl;
    std::cout << eggDrop(3, 2) << std::endl;
}
