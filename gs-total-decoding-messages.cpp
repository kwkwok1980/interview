//https://practice.geeksforgeeks.org/problems/total-decoding-messages/0
#include <iostream>

int SolveInternal(const std::string& values, int N, int n, int results[])
{
    if (n > N)
    {
        return 0;
    }

    if (n == N)
    {
        return 1;
    }

    if (results[n] != -1)
    {
        return results[n];
    }

    int value1 = values[n] - '0';
    if (value1 == 0)
    {
        results[n] = 0;
    }
    else
    {
        results[n] = SolveInternal(values, N, n+1, results);
        if (n+1 < N)
        {
            int value2 = values[n+1] - '0';
            if ((value1 == 1) || (value1 == 2 && value2 <= 6))
            {
                results[n] += SolveInternal(values, N, n+2, results);
            }
        }
    }
    return results[n];
}

void Solve(const std::string& values, int N)
{
    int results[N];
    for (int i=0; i<N; ++i)
    {
        results[i] = -1;
    }
    SolveInternal(values, N, 0, results);
    std::cout << results[0] << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;
    std::string S{};
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::cin >> S;
        Solve(S, N);
    }
    return 0;
}
