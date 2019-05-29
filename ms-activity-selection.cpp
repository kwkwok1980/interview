//https://practice.geeksforgeeks.org/problems/activity-selection/0

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <memory>
#include <unordered_map>

using Schedule = std::pair<int, int>;
using Schedules = std::vector<Schedule>;

void Print(const Schedules& schedules)
{
    for (auto& schedule : schedules)
    {
        std::cout << "[" << schedule.first << " " << schedule.second << "] ";
    }
    std::cout << std::endl;
}

void Solve(Schedules& schedules)
{
    auto sorting = [](const Schedule& a, const Schedule& b){return a.second < b.second;};
    std::sort(schedules.begin(), schedules.end(), sorting);
    //Print(schedules);

    int count = 1;
    Schedule& current = schedules[0];
    for (int i=1; i<schedules.size(); ++i)
    {
        Schedule& next = schedules[i];
        if (next.first >= current.second)
        {
            ++count;
            current = next;
        }
    }
    std::cout << count << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        Schedules schedules(N);
        for (int n=0; n<N; ++n)
        {
            int start;
            std::cin >> start;
            schedules[n].first = start;
        }

        for (int n=0; n<N; ++n)
        {
            int end;
            std::cin >> end;
            schedules[n].second = end;
        }

        Solve(schedules);
    }
    return 0;
}
