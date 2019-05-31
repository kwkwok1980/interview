//https://practice.geeksforgeeks.org/problems/odd-to-even/0

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

void Solve(std::string& s)
{
    std::size_t len = s.length();
    int right = s[len-1] - '0';
    int index = -1;
    for (int i=0; i<len; ++i)
    {
        int value = s[i] - '0';
        if (value % 2 == 0)
        {
            index = i;
            if (value < right)
            {
                break;
            }
        }
    }

    if (index != -1)
    {
        s[len-1] = s[index];
        s[index] = right + '0';

    }
    std::cout << atoi(s.c_str()) << std::endl;
}

int main()
{
    int T = 0;
    std::string s{};
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> s;
        Solve(s);
    }
    return 0;
}
