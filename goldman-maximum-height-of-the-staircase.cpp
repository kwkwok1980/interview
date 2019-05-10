//https://practice.geeksforgeeks.org/problems/maximum-height-of-the-staircase/0

#include <stack>
#include <iostream>
#include <vector>

std::int64_t StairCase(std::int64_t N)
{
    return N*(N+1)/2;
}

std::int64_t Solve(std::int64_t N)
{
    std::int64_t begin = 1;
    std::int64_t end = N;
    std::int64_t result = 0;
    while (begin <= end)
    {
        std::int64_t current = (begin+end)/2;
        std::int64_t s = StairCase(current);
        //std::cout << begin << " " << current << " " << end << " " << s << std::endl;
        if (s == N)
        {
            result = current;
            break;
        }
        else if (s > N)
        {
            end = current-1;
        }
        else
        {
            result = current;
            begin = current+1;
        }
    }
    return result;
}

int main() {
    std::int64_t N = 0;
    std::cin >> N;
    std::vector<std::int64_t> values{};
    for (std::int64_t n=0; n<N; ++n)
    {
        std::int64_t value = 0;
        std::cin >> value;
        values.push_back(value);
    }

    for (std::int64_t value : values)
    {
        std::cout << Solve(value) << std::endl;
    }
}
