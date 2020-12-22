#include <iostream>


int SolveInternal(const std::string& s1, const std::string& s2)
{
    if (s1.length() != s2.length())
    {
        return 0;
    }

    int a = -1;
    int b = -1;
    int length = s1.length();
    for (int i=0; i<length; ++i)
    {
        if (s1[i] != s2[i])
        {
            if (a == -1)
            {
                a = i;
            }
            else if (b == -1)
            {
                b = i;
            }
            else
            {
                return 0;
            }
        }
    }

    if (a == -1 && b == -1)
    {
        return 0;
    }

    if (s1[a] == s2[b] && s1[b] == s2[a])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Solve(const std::string& s1, const std::string& s2)
{
    int k = SolveInternal(s1, s2);
    std::cout << k << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::string s1{};
        std::string s2{};
        std::cin >> s1;
        std::cin >> s2;
        Solve(s1, s2);
    }
    return 0;
}
