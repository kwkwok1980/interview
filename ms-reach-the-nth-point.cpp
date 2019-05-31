//https://practice.geeksforgeeks.org/problems/reach-the-nth-point/0

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

static const std::int64_t MAX = 90;
static std::int64_t results[MAX+1];

std::int64_t SolveInternal(std::int64_t N)
{
    results[N] = results[N-1] + results[N-2];
    return results[N];
}

void Solve(std::int64_t N)
{
    results[0] = 0;
    results[1] = 1;
    results[2] = 2;
    for (std::int64_t n=3; n<=N; ++n)
    {
        SolveInternal(n);
    }
    std::cout << results[N] << std::endl;
}

int main()
{
    std::int64_t T = 0;
    std::int64_t N = 0;
    std::cin >> T;
    for (std::int64_t t=0; t<T; ++t)
    {
        std::cin >> N;
        Solve(N);
    }
    return 0;
}
