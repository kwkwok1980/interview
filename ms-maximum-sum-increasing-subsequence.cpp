//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>

using Data = std::pair<int, int>;

void Solve(const std::vector<int>& values)
{
    std::set<Data, std::greater<Data>> results{};
    results.emplace(values[0], values[0]);

    int max = values[0];

    for (int i=1; i < values.size(); ++i)
    {
        int current = 0;
        for (auto& result : results)
        {
            if (result.second < values[i])
            {
                current = result.first;
                break;
            }
        }

        current = current + values[i];
        results.emplace(current, values[i]);
        max = std::max(max, current);
    }
    std::cout << max << std::endl;
}

void Solve2(const std::vector<int>& values)
{
    std::vector<int> results(values.size());
    results[0] = values[0];
    int max = values[0];

    for (int i=1; i < values.size(); ++i)
    {
        for (int j=i-1; j>=0; --j)
        {
            if (values[j] < values[i])
            {
                results[i] = std::max(results[i], results[j]);
            }
        }
        results[i] += values[i];
        max =std::max(max, results[i]);
    }
    std::cout << max << std::endl;
}

int main() {
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        int value = 0;
        std::vector<int> values{};
        for (int n=0; n<N; ++n)
        {
            std::cin >> value;
            values.emplace_back(value);
        }
        Solve(values);
    }
    //code
    return 0;
}

