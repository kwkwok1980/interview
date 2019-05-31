//https://practice.geeksforgeeks.org/problems/minimum-distinct-ids/0

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

void Solve(int M, const std::vector<int>& values)
{
    std::unordered_map<int, int> valuesMap{};
    for (int value : values)
    {
        ++valuesMap[value];
    }

    std::vector<int> results{};
    for(auto& pair : valuesMap)
    {
        results.emplace_back(pair.second);
    }

    std::sort(results.begin(), results.end());
    int count = results.size();
    for (int result : results)
    {
        if (M >= result)
        {
            --count;
            M -= result;
        }
        else
        {
            break;
        }
    }

    std::cout << count << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;
    int M = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::vector<int> values(N);
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }
        std::cin >> M;
        Solve(M, values);
    }
    return 0;
}
