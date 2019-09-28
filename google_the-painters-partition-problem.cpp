//https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0

constexpr const int K_MAX = 30+1;
constexpr const int N_MAX = 50+1;

int SolveInternal(int N, int values[], int k, int n, int results[K_MAX][N_MAX])
{
    if (results[k][n] != -1)
    {
        //std::cout << k << " " << n << " " << results[k][n] << std::endl;
        return results[k][n];
    }

    if (n == N)
    {
        results[k][n] = 0;
        //std::cout << k << " " << n << " " << results[k][n] << std::endl;
        return results[k][n];
    }

    if (k == 0)
    {
        results[k][n] = std::numeric_limits<int>::max();
        //std::cout << k << " " << n << " " << results[k][n] << std::endl;
        return results[k][n];
    }

    int value = 0;
    int result = std::numeric_limits<int>::max();
    for (int i=n; i<N; ++i)
    {
        value += values[i];
        result = std::min(result, std::max(value, SolveInternal(N, values, k-1, i+1, results)));
    }

    results[k][n] = result;
    //std::cout << k << " " << n << " " << results[k][n] << std::endl;
    return results[k][n];
}

void Solve(int K, int N, int values[])
{
    int results[K_MAX][N_MAX]{};
    for (int k=0; k<K_MAX; ++k)
    {
        for (int n=0; n<N_MAX; ++n)
        {
            results[k][n] = -1;
        }
    }

    int result = SolveInternal(N, values, K, 0, results);
    std::cout << result << std::endl;
}

int main()
{
    int T = 0;
    int K = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> K;
        std::cin >> N;
        int values[N];
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }
        Solve(K, N, values);

    }


    //code
    return 0;
}
