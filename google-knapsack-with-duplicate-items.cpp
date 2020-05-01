#include <cstring>
#include <iostream>
#include <algorithm>

const int max = 1000;
int results[max + 1]{};
int values[max+ 1]{};
int weights[max + 1]{};

int SolveInternal(int N, int W)
{
    if (results[W] != -1)
    {
        return results[W];
    }

    int result = 0;
    for (int n=0; n<N; ++n)
    {
        if (W >= weights[n])
        {
            result = std::max(result, values[n] + SolveInternal(N, W - weights[n]));
        }
    }
    results[W] = result;
    return result;
}

void Solve(int N, int W)
{
    std::fill(results, results + max, -1);

    for (int n=0; n<N; ++n)
    {
        std::cin >> values[n];
    }

    for (int n=0; n<N; ++n)
    {
        std::cin >> weights[n];
    }

    std::cout << SolveInternal(N, W) << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        int N = 0;
        int W = 0;
        std::cin >> N;
        std::cin >> W;
        Solve(N, W);
    }
    return 0;
}
