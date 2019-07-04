//https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number/0
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
#include <cmath>
#include <iostream>

void Solve(int N, int K, const std::vector<int>& values)
{
    std::unordered_map<int, int> results{};
    for (int n=0; n<N; ++n)
    {
        int mod = values[n]%K;
        ++results[mod];
    }

    for (auto& result : results)
    {
        if (result.first == 0)
        {
            if (result.second % 2 != 0)
            {
                std::cout << "False" << std::endl;
                return;
            }
        }
        else
        {
            if (result.second != results[K - result.first])
            {
                std::cout << "False" << std::endl;
                return;
            }
        }
    }

    std::cout << "True" << std::endl;
}

int main() {
    int T = 0;
    int N = 0;
    int K = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::vector<int> values(N);
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }
        std::cin >> K;
        Solve(N, K, values);
    }
    return 0;
}
