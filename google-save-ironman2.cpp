#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

void Solve(const std::string& s)
{
    int end = s.length();
    for (int a=0; a<end; ++a)
    {
        if (!std::isalnum(s[a]))
        {
            continue;
        }

        for (int b = end - 1; b >= a; --b)
        {
            if (std::isalnum(s[b]))
            {
                if (std::tolower(s[b]) == std::tolower(s[a]))
                {
                    end = b;
                    break;
                }
                else
                {
                    std::cout << "NO" << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << "YES" << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    std::string s{};
    std::getline(std::cin, s);
    for (int t=0; t<T; ++t)
    {
        std::getline(std::cin, s);
        Solve(s);
    }
}
