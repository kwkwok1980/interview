//https://practice.geeksforgeeks.org/problems/number-following-a-pattern/0
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

void Solve(const std::string& pattern)
{
    int N = pattern.size();
    char results [N+2];
    for (int n=0; n<N+1; ++n)
    {
        results[n] = '1' + n;
    }
    results[N+1] = 0;
    //std::cout << results << std::endl;

    int start = 0;
    int end = 0;
    while (start != N)
    {
        while (pattern[start] != 'D' && start < N)
        {
            ++start;
        }

        if (start != N)
        {
            end = start;
            while (pattern[end] == 'D' && end < N)
            {
                ++end;
            }
            std::reverse(results+start, results+1+end);
            start = end;
        }
    }
    std::cout << results << std::endl;

}

int main() {
    int T = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::string pattern{};
        std::cin >> pattern;
        Solve(pattern);
    }
    return 0;
}
