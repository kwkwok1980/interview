#include <iostream>

int results[1001][2][3]{};


int SolveInternal(int N, int b, int c)
{
    if (results[N][b][c] != 0)
    {
        return results[N][b][c];
    }

    int k = 0;
    if (N == 1)
    {
        ++k;
        if (b > 0) ++k;
        if (c > 0) ++k;
    }
    else
    {
        k = k + SolveInternal(N-1, b, c);
        if (b > 0) k = k + SolveInternal(N-1, b-1, c);
        if (c > 0) k = k + SolveInternal(N-1, b, c-1);
    }
    results[N][b][c] = k;
    return k;
}

void Solve(int n, int b, int c)
{
    std::cout << SolveInternal(n, b, c) << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int i=0; i<T; ++i)
    {
        int N = 0;
        std::cin >> N;
        Solve(N, 1, 2);
    }
    return 0;
}
