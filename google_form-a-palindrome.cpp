////https://practice.geeksforgeeks.org/problems/form-a-palindrome/0

#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

const int MAX = 41;

int SolveInternal(const std::string& s, int left, int right, int (&results) [MAX][MAX])
{
    if (results[left][right] != -1)
    {
        return results[left][right];
    }

    if (left == right)
    {
        results[left][right] = 0;
        return results[left][right];
    }

    int result = std::numeric_limits<int>::max();
    result = std::min(result, SolveInternal(s, left+1, right, results) + 1);
    result = std::min(result, SolveInternal(s, left, right-1, results) + 1);
    if (s[left] == s[right])
    {
        if (left + 1 == right)
        {
            result = 0;
        }
        else
        {
            result = std::min(result, SolveInternal(s, left+1, right-1, results));
        }
    }

    results[left][right] = result;
    return results[left][right];
}

void Solve(const std::string& s)
{
    int results[MAX][MAX];
    for (int i=0; i<MAX; ++i)
    {
        for (int j=0; j<MAX; ++j)
        {
            results[i][j] = -1;
        }
    }

    SolveInternal(s, 0, s.size()-1, results);
    std::cout << results[0][s.size()-1] << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::string s{};
        std::cin >> s;
        Solve(s);
    }

    //code
    return 0;
}
