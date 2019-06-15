//https://practice.geeksforgeeks.org/problems/minimum-cost-path/0

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
#include <fstream>
#include <queue>
#include <stack>

using Point = std::pair<int,int>;
static const int MAX = 100;

void Solve(int values[MAX][MAX], int N)
{
    int results[MAX][MAX]{};
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            results[i][j] = std::numeric_limits<int>::max();
        }
    }

    std::queue<Point> tasks{};
    auto task = [&](int i, int j, int score)
    {
        if (i>=0 && i<N && j>=0 && j<N)
        {
            if (results[i][j] > score + values[i][j])
            {
                results[i][j] = score + values[i][j];
                tasks.emplace(i, j);
            }
        }
    };

    results[0][0] = values[0][0];
    tasks.emplace(0, 0);
    while (!tasks.empty())
    {
        Point point = tasks.front();
        tasks.pop();

        int i = point.first;
        int j = point.second;
        int score = results[i][j];
        task(i - 1, j, score);
        task(i + 1, j, score);
        task(i, j-1, score);
        task(i, j+1, score);
    }

    std::cout << results[N-1][N-1] << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;

    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        int values[MAX][MAX]{};
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j)
            {
                std::cin >> values[i][j];
            }
        }
        Solve(values, N);
    }
    return 0;
}
