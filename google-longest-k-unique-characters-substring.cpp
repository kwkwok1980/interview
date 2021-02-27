//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <list>
#include <mutex>
#include <atomic>
#include <memory>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <c++/8/sstream>
#include <ranges>

void Solve(const std::string& value, int K)
{
    int begin = 0;
    int end = 0;
    int result = 0;
    std::unordered_map<char, int> cache{};

    for (char c : value)
    {
        cache[c] = cache[c] + 1;
        ++end;

        while (cache.size() > K)
        {
            char r = value[begin];
            cache[r] = cache[r] - 1;
            if (cache[r] == 0)
            {
                cache.erase(r);
            }
            ++begin;
        }
        result = std::max(result, end - begin);
    }

    std::cout << result << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::string value{};
        std::cin >> value;

        int K = 0;
        std::cin >> K;

        Solve(value, K);
    }
}
