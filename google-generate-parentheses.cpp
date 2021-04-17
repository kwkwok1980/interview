//https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/

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
#include <map>
#include <sstream>
#include <limits>
#include <functional>
#include <numeric>
#include <execution>
#include <bitset>
#include <iomanip>

class Solution
{
public:
    std::vector<std::string> AllParenthesis(int N)
    {
        std::vector<std::string> results{};
        auto solver = [&](auto&& self, const std::string& result, int start, int end)
        {
            if (start == N && end ==N)
            {
                results.emplace_back(result);
                return;
            }

            if (start < N)
            {
                self(self, result + "(", start + 1, end);
            }

            if (end < start)
            {
                self(self, result + ")", start, end + 1);
            }
        };

        solver(solver, "", 0, 0);
        return results;
    }
};
