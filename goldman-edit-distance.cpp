//https://practice.geeksforgeeks.org/problems/edit-distance/0

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>

int results[100+1][100+1];

int SolveInternal(const std::string& s1, const std::string& s2, int P, int Q, int p, int q)
{
    if (results[p][q] != -1)
    {
        //std::cout << p << " " << q << " " << results[p][q] << std::endl;
        return results[p][q];
    }

    if (P == p && Q == q)
    {
        results[p][q] = 0;
        return results[p][q];
    }

    if (P == p)
    {
        results[p][q] = Q-q;
        return results[p][q];
    }

    if (Q == q)
    {
        results[p][q] = P-p;
        return results[p][q];
    }

    int total = std::numeric_limits<int>::max();

    //Replace
    int cost1 = (s1[p] == s2[q] ? 0 : 1) + SolveInternal(s1, s2, P, Q, p+1, q+1);
    total = std::min(total, cost1);

    //Add
    int cost2 = 1 + SolveInternal(s1, s2, P, Q, p, q+1);
    total = std::min(total, cost2);

    //Remove
    int cost3 = 1 + SolveInternal(s1, s2, P, Q, p+1, q);
    total = std::min(total, cost3);

    results[p][q] = total;
    return results[p][q];
}

void Solve(const std::string& s1, const std::string& s2, int P, int Q)
{
    for (int p=0; p<=P; ++p)
    {
        for(int q=0; q<=Q; ++q)
        {
            results[p][q] = -1;
        }
    }

    std::cout << SolveInternal(s1, s2, P, Q, 0, 0) << std::endl;
}

int main()
{
    int T = 0;
    int P = 0;
    int Q = 0;
    std::string s1;
    std::string s2;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> P;
        std::cin >> Q;
        std::cin >> s1;
        std::cin >> s2;
        Solve(s1, s2, P, Q);
    }

    return 0;
}
