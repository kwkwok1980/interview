//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0

#include <limits>

void Solve(const std::string& s1, const std::string& s2)
{
    int results[26]{};
    for (auto c : s2)
    {
        ++results[c - 'a'];
    }

    auto done = [&results]()
    {
        for (auto result : results)
        {
            if (result > 0)
            {
                return false;
            }
        }
        return true;
    };

    int result = std::numeric_limits<int>::max();
    int begin = 0;
    int end = 0;
    int size = s1.size();
    int minBegin = -1;
    int minEnd = -1;

    while (begin < size && end < size)
    {
        while (!done() && end < size)
        {
            --results[s1[end] - 'a'];
            ++end;
        }

        while (done() && begin < end)
        {
            if (result > (end - begin))
            {
                result = (end - begin);
                minBegin = begin;
                minEnd = end;
            }
            ++results[s1[begin] - 'a'];
            ++begin;
        }
    }

    if (minBegin != -1 && minEnd != -1)
    {
        std::cout << s1.substr(minBegin, minEnd - minBegin) << std::endl;
    }
    else
    {
        std::cout << -1 << std::endl;
    }
}

int main()
{
    int T = 0;
    std::string S1{};
    std::string S2{};

    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> S1;
        std::cin >> S2;
        Solve(S1, S2);
    }
    return 0;
}
