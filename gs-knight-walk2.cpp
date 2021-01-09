//https://practice.geeksforgeeks.org/problems/knight-walk/0#

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <deque>

const int MAX = 25 + 1;
int results[MAX][MAX];

struct Point
{
    Point(int p1_, int p2_) :
        p1{p1_}, p2{p2_}
    {}

    int p1;
    int p2;
};

void SolveInternal(int N, int M, int s1, int s2)
{
    std::vector<std::pair<int,int>> steps =
    {
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {-1, 2},
    };

    results[s1][s2] = 0;
    std::deque<Point> points{};
    points.emplace_back(s1, s2);

    while(!points.empty())
    {
        Point point = points.front();
        points.pop_front();
        for (const auto& step : steps)
        {
            int x1 = point.p1 + step.first;
            int x2 = point.p2 + step.second;
            if (x1 >=1 && x1 <= N && x2>=1 && x2 <= M)
            {
                if (results[x1][x2] == -1 || results[x1][x2] > results[point.p1][point.p2] + 1)
                {
                    results[x1][x2] = results[point.p1][point.p2] + 1;
                    points.emplace_back(x1, x2);
                }
            }
        }
    }
}

void Solve(int N, int M, int s1, int s2, int d1, int d2) {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            results[i][j] = -1;
        }
    }

    SolveInternal(N, M, s1, s2);
    std::cout << results[d1][d2] << std::endl;
}

int main() {
    int T = 0;
    int N = 0;
    int M = 0;
    int s1, s2, d1, d2;

    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::cin >> N;
        std::cin >> M;
        std::cin >> s1;
        std::cin >> s2;
        std::cin >> d1;
        std::cin >> d2;

        Solve(N, M, s1, s2, d1, d2);
    }
}
