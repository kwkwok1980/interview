//https://practice.geeksforgeeks.org/problems/count-the-numbers/0

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

bool Match(int N)
{
    static char c0 = '0' + 0;
    static char c5 = '0' + 5;
    std::string s = std::to_string(N);
    for (int i = s.size()-1; i>-1; --i)
    {
        char c = s[i];
        if (c == c0 || c > c5)
        {
            return false;
        }
    }
    return true;
}

void Solve(int N)
{
    int count = 0;
    for (int n=1; n<=N; ++n)
    {
        if (Match(n))
        {
            ++count;
        }
    }
    std::cout << count << std::endl;
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
    return 0;
}
