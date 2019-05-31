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
    for (int i=len-2; i>=0; --i)
    {
        int left = s[i] - '0';
        int index = -1;
        for (int j=i+1; j<=len-1; ++j)
        {
            int right = s[j] - '0';
            if (right > left)
            {
                if (index == -1)
                {
                    index = j;
                }
                else if (right < s[index] - '0')
                {
                    index = j;
                }
            }
        }

        if (index != -1)
        {
            s[i] = s[index];
            s[index] = left + '0';
            std::sort(s.begin()+i+1, s.end());
            std::cout << s << std::endl;
            return;
        }
    }

    std::cout << "not possible" << std::endl;
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
