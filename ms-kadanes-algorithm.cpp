https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

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
#include <fstream>

void Solve(const std::vector<int>& values)
{
    int max = -1000000000;
    int current = 0;
    for (int value : values)
    {
        if (current > 0)
        {
            current = current + value;
        }
        else
        {
            current = value;
        }
        max = std::max(current, max);
    }
    std::cout << max << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::vector<int> values(N);
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }
        Solve(values);
    }
    return 0;
}

