//https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not/0

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

void Solve(const std::vector<int> values1, const std::vector<int> values2)
{
    std::unordered_map<int, int> results{};
    for (auto& value1 : values1)
    {
        ++results[value1];
    }

    for (auto& value2 : values2)
    {
        --results[value2];
    }

    for (auto& result : results)
    {
        if (result.second != 0)
        {
            std::cout << 0 << std::endl;
            return;
        }
    }

    std::cout << 1 << std::endl;
}


int main() {
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::vector<int> values1{};
        for (int n=0; n<N; ++n)
        {
            int X;
            std::cin >> X;
            values1.emplace_back(X);
        }

        std::vector<int> values2{};
        for (int n=0; n<N; ++n)
        {
            int X;
            std::cin >> X;
            values2.emplace_back(X);
        }

        Solve(values1, values2);
    }
}
