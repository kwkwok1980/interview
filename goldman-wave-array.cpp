//https://practice.geeksforgeeks.org/problems/wave-array/0

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

void Solve(const std::vector<int>& values)
{
    for (int i=0; i<values.size(); ++i)
    {
        if (i+1 < values.size())
        {
            ++i;
            std::cout << values[i] << " " << values[i-1] << " ";
        }
        else
        {
            std::cout << values[i];
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
        std::vector<int> values{};
        for (int n=0; n<N; ++n)
        {
            int X;
            std::cin >> X;
            values.emplace_back(X);
        }
        Solve(values);
    }
}
