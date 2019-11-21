#include <iostream>
#include <unordered_set>
#include <cmath>
#include <array>
#include <unordered_map>
#include <vector>
#include <limits>
#include <bitset>

constexpr std::size_t MAX = 30;
using Jobs = std::uint32_t[MAX][MAX];
using Status = std::uint32_t;
using Result = std::unordered_map<Status, std::uint32_t>[MAX];

std::uint32_t SolveInternal(std::size_t N, Jobs& jobs, std::size_t n, Status status, Result& result)
{
    std::cout << status << std::endl;
    if (n >= N)
    {
        return 0;
    }

    if (result[n][status] != 0)
    {
        return result[n][status];
    }

    std::uint32_t minValue = std::numeric_limits<std::uint32_t>::max();
    for (std::size_t i=0; i<N; ++i)
    {
        std::uint32_t newStatus = 1;
        newStatus = newStatus << i;

        if ((status & newStatus) == 0)
        {
            std::uint32_t newValue =  SolveInternal(N, jobs, n+1, status | newStatus, result);
            if (newValue != 0)
            {
                newValue = newValue + jobs[n][i];
            }
            else
            {
                newValue = jobs[n][i];
            }
            minValue = std::min(minValue, newValue);
        }
    }
    result[n][status] = minValue;
    return minValue;
}

void Solve(std::size_t N, Jobs& jobs)
{
    Status status{};
    Result result{};
    std::uint32_t minValue = SolveInternal(N, jobs, 0, status, result);
    std::cout << minValue << std::endl;
}

int main()
{
    std::size_t T = 0;
    std::size_t N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        Jobs jobs{};
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j)
            {
                std::cin >> jobs[i][j];
            }
        }

        Solve(N, jobs);
    }

    return 0;
}
