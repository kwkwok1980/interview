//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0

#include <stack>
#include <iostream>
#include <vector>

int count = 0;

const int MAX_N = 10 + 1;
const int MAX_K = 50 + 1;
int results[MAX_N][MAX_K];

void ResetResults()
{
    for(int i=0; i<MAX_N; ++i)
    {
        for(int j=0; j<MAX_K; ++j)
        {
            results[i][j] = -1;
        }
    }
}

int Solve(int N, int K)
{
    ++count;
    //if (count % 100 == 0)
    //{
    //    std::cout << count << " " <<  N << " " << K << std::endl;
    //}

    if (results[N][K] != -1)
    {
        return results[N][K];
    }

    if (N == 1)
    {
        results[N][K] = K;
        return results[N][K];
    }

    if (K == 0)
    {
        results[N][K] = 0;
        return results[N][K];
    }

    //int result = std::numeric_limits<int>::max();
    int result = 2147483647;
    for (int x=1; x<=K; ++x)
    {
        result = std::min(result, 1+ std::max(Solve(N,K-x), Solve(N-1, x-1)));
    }

    results[N][K] = result;
    return results[N][K];
}

int main() {
    int T, N, K = 0;
    std::cin >> T;
    for(int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::cin >> K;
        ResetResults();
        std::cout << Solve(N, K) << std::endl;
    }
}
