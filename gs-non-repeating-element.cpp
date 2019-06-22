//https://practice.geeksforgeeks.org/problems/non-repeating-element/0

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <fstream>
#include <queue>
#include <stack>

void Solve(int N)
{
    std::unordered_map<std::int64_t, std::int64_t> counts{};
    std::vector<std::int64_t> values{};

    counts.reserve(N);
    values.reserve(N);

    std::int64_t value{};
    for (std::int64_t n=0; n<N; ++n)
    {
        std::cin >> value;
        auto itFind = counts.find(value);
        if (itFind == counts.end())
        {
            counts.emplace(value, 0);
            values.push_back(value);
        }
        else
        {
            itFind->second = 1;
        }
    }

    for (auto i : values)
    {
        if (counts[i] == 0)
        {
            std::cout << i << std::endl;
            return;
        }
    }

    std::cout << 0 << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;

    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        Solve(N);
    }
}
