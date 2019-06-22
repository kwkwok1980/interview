//https://practice.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array/0
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
    const int MAX = std::numeric_limits<int>::max();
    int min1 = MAX;
    int min2 = MAX;
    int value = 0;
    for (std::int64_t n=0; n<N; ++n)
    {
        std::cin >> value;
        if (value < min1)
        {
            min2 = min1;
            min1 = value;
        }
        else if (value == min1)
        {

        }
        else if (value < min2)
        {
            min2 = value;
        }
    }

    if (min1 == MAX || min2 == MAX)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << min1 << " " << min2 << std::endl;
    }
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
