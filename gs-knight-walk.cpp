//https://practice.geeksforgeeks.org/problems/knight-walk/0

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

const int MAX = 25 + 1;
int results[MAX][MAX];

struct Point {
    Point(int x1_, int x2_, int count_) {
        x1 = x1_;
        x2 = x2_;
        count = count_;
    }

    int x1;
    int x2;
    int count;
};

void SolveBFS(int N, int M, int s1, int s2, int d1, int d2) {
    std::queue<Point> values{};
    values.emplace(s1, s2, 0);

    while (!values.empty()) {
        Point point = values.front();
        values.pop();
        if (1 <= point.x1 && point.x1 <= N && 1 <= point.x2 && point.x2 <= M) {
            if (results[point.x1][point.x2] == -1 || results[point.x1][point.x2] > point.count) {
                results[point.x1][point.x2] = point.count;

                values.emplace(point.x1 + 1, point.x2 + 2, point.count + 1);
                values.emplace(point.x1 + 2, point.x2 + 1, point.count + 1);
                values.emplace(point.x1 + 2, point.x2 - 1, point.count + 1);
                values.emplace(point.x1 + 1, point.x2 - 2, point.count + 1);
                values.emplace(point.x1 - 1, point.x2 + 2, point.count + 1);
                values.emplace(point.x1 - 2, point.x2 + 1, point.count + 1);
                values.emplace(point.x1 - 2, point.x2 - 1, point.count + 1);
                values.emplace(point.x1 - 1, point.x2 - 2, point.count + 1);
            }
        }
    }
}

void SolveDFS(int N, int M, int s1, int s2, int d1, int d2, int count) {
    if (s1 < 1 || s1 > N) {
        return;
    }

    if (s2 < 1 || s2 > M) {
        return;
    }

    if (results[s1][s2] != -1 && results[s1][s2] <= count) {
        return;
    }

    results[s1][s2] = count;
    SolveDFS(N, M, s1 + 1, s2 + 2, d1, d2, count + 1);
    SolveDFS(N, M, s1 + 2, s2 + 1, d1, d2, count + 1);
    SolveDFS(N, M, s1 + 2, s2 - 1, d1, d2, count + 1);
    SolveDFS(N, M, s1 + 1, s2 - 2, d1, d2, count + 1);
    SolveDFS(N, M, s1 - 1, s2 + 2, d1, d2, count + 1);
    SolveDFS(N, M, s1 - 2, s2 + 1, d1, d2, count + 1);
    SolveDFS(N, M, s1 - 2, s2 - 1, d1, d2, count + 1);
    SolveDFS(N, M, s1 - 1, s2 - 2, d1, d2, count + 1);
}

void Solve(int N, int M, int s1, int s2, int d1, int d2) {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            results[i][j] = -1;
        }
    }

    //SolveDFS(N, M, s1, s2, d1, d2, 0);
    SolveBFS(N, M, s1, s2, d1, d2);

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
