//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

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

void Solve(int N, const int* const values)
{
    int counts[3]{};
    for (int i=0; i<N; ++i)
    {
        ++counts[values[i]];
    }

    for (int i=0; i<3; ++i)
    {
        for (int j=0; j<counts[i]; ++j)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::unique_ptr<int[]> values{new int[N]};
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }

        Solve(N, values.get());
    }
    return 0;
}
