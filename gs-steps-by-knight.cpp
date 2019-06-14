//https://practice.geeksforgeeks.org/problems/steps-by-knight/0

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

using point = std::pair<int,int>;

void Solve1(int N, point k, point g)
{
    int results[100][100];
    for (int i=0; i<N+1; ++i)
    {
        for (int j=0; j<N+1; ++j)
        {
            results[i][j] = std::numeric_limits<int>::max();
        }
    }

    std::stack<point> points{};
    results[k.first][k.second] = 0;
    points.push(k);

    auto job = [&](int i, int j, int score)
    {
        if (i>=1 && i<=N && j>=1 && j<=N)
        {
            if (results[i][j] > 1 + score)
            {
                results[i][j] = 1 + score;
                points.emplace(i, j);
            }
        }
    };

    while(!points.empty())
    {
        point p = points.top();
        points.pop();

        int score = results[p.first][p.second];
        job(p.first + 2, p.second + 1, score);
        job(p.first + 1, p.second + 2, score);
        job(p.first - 1, p.second + 2, score);
        job(p.first - 2, p.second + 1, score);
        job(p.first + 2, p.second - 1, score);
        job(p.first + 1, p.second - 2, score);
        job(p.first - 1, p.second - 2, score);
        job(p.first - 2, p.second - 1, score);
    }

    if (results[g.first][g.second] != std::numeric_limits<int>::max())
    {
        std::cout << results[g.first][g.second] << std::endl;
    }
    else
    {
        std::cout << 1 << std::endl;
    }
}

void Solve2(int N, point k, point g)
{
    int results[100][100];
    for (int i=0; i<N+1; ++i)
    {
        for (int j=0; j<N+1; ++j)
        {
            results[i][j] = std::numeric_limits<int>::max();
        }
    }

    std::queue<point> points{};
    results[k.first][k.second] = 0;
    points.push(k);

    auto job = [&](int i, int j, int score)
    {
        if (i>=1 && i<=N && j>=1 && j<=N)
        {
            if (results[i][j] > 1 + score)
            {
                results[i][j] = 1 + score;
                points.emplace(i, j);
            }
        }
    };

    while(!points.empty())
    {
        point p = points.front();
        points.pop();

        int score = results[p.first][p.second];
        job(p.first + 2, p.second + 1, score);
        job(p.first + 1, p.second + 2, score);
        job(p.first - 1, p.second + 2, score);
        job(p.first - 2, p.second + 1, score);
        job(p.first + 2, p.second - 1, score);
        job(p.first + 1, p.second - 2, score);
        job(p.first - 1, p.second - 2, score);
        job(p.first - 2, p.second - 1, score);
    }

    if (results[g.first][g.second] != std::numeric_limits<int>::max())
    {
        std::cout << results[g.first][g.second] << std::endl;
    }
    else
    {
        std::cout << 1 << std::endl;
    }
}

int main()
{
    int T = 0;
    int N = 0;
    point k{};
    point g{};

    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::cin >> k.first;
        std::cin >> k.second;
        std::cin >> g.first;
        std::cin >> g.second;
        Solve2(N, k, g);
    }
    return 0;
}
