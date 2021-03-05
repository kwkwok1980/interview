//https://practice.geeksforgeeks.org/problems/surpasser-count0615/1

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

class Solution1
{

public:
    std::vector<int> findSurpasser(int arr[], int N)
    {
        std::set<int> values{};
        std::vector<int> results(N);
        for (int i=N-1; i>=0; --i)
        {
            auto [it, _] = values.insert(arr[i]);
            results[i] = distance(it, values.end()) - 1;
        }
        return results;
    }
};

class Solution2
{

public:
    std::vector<int> findSurpasser(int arr[], int N)
    {
        std::vector<int> results(N);
        std::vector<int> values{};
        for (int i=N-1; i>=0; --i)
        {
            auto it = std::lower_bound(values.begin(), values.end(), arr[i]);
            auto n = std::distance(it, values.end());
            results[i] = n;
            values.insert(it, arr[i]);
        }
        return results;
    }
};

using Solution = Solution2;

int main()
{
    int arr[] = {2, 7, 5, 3, 8, 1};

    Solution solution{};
    auto results = solution.findSurpasser(arr, 6);
    std::copy(results.begin(), results.end(), std::ostream_iterator<int>(std::cout, " "));
}
