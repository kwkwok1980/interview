//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0

#include <stack>
#include <iostream>
#include <vector>
#include <queue>

void Solve(const std::vector<std::int64_t>& values)
{
    using queue_type = std::priority_queue<std::int64_t, std::vector<std::int64_t>, std::greater<std::int64_t>>;
    queue_type queues{values.begin(), values.end()};

    std::int64_t cost = 0;
    while(queues.size() > 1)
    {
        std::int64_t min1 = queues.top();
        queues.pop();

        std::int64_t min2 = queues.top();
        queues.pop();

        std::int64_t min3 = min1 + min2;
        //std::cout << min1 << " " << min2 << " " << min3 << std::endl;
        cost += min3;
        queues.push(min3);
    }

    std::cout << cost << std::endl;
}

int main() {

    std::int64_t T, N;
    std::cin >> T;
    for (std::int64_t t=0; t<T; ++t)
    {
        std::cin >> N;
        std::vector<std::int64_t> values{};
        for (std::int64_t n=0; n<N; ++n)
        {
            std::int64_t i ;
            std::cin >> i;
            values.push_back(i);
        }
        Solve(values);
    }
}
