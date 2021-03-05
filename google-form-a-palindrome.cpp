//https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1

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

class Solution{
private:
    int results[41][41]{};

    int solve(const std::string& value, int i, int j)
    {
        int& result = results[i][j];

        if (result != -1)
        {
            return result;
        }

        if (i == j)
        {
            result = 0;
            return result;
        }

        result = 1 + std::min(solve(value, i+1, j), solve(value, i, j-1));
        if (value[i] == value[j])
        {
            if (i+1 == j)
            {
                result = 0;
            }
            else
            {
                result = std::min(result, solve(value, i+1, j-1));
            }
        }
        return result;
    }

public:
    int findMinInsertions(std::string value)
    {
        for (int i=0; i<41; ++i)
        {
            for (int j=0; j<41; ++j)
            {
                results[i][j] = -1;
            }
        }
        return solve(value, 0, value.size()-1);
    }
};

int main()
{
    Solution solution{};
    std::string s = "geeks"; //s geek s => sk gee ks => skg ee gks

    int result = solution.findMinInsertions(s);
    std::cout << result << std::endl;


}
