//https://www.geeksforgeeks.org/number-subarrays-product-less-k/

#include <iostream>
#include <array>
#include <vector>

std::int64_t Solve(const std::vector<std::int64_t>& values, std::int64_t N, std::int64_t K)
{
    std::int64_t result = 1;
    std::int64_t count = 0;
    std::int64_t n = 0;

    for (std::int64_t i=0; i<N; ++i)
    {
        for (std::int64_t j=n; j<N; ++j)
        {
            if (result * values[j] >= K)
            {
                break;
            }

            result = result * values[j];
            ++n;
        }

        if (n>i)
        {
            count += (n-i);
            result = result / values[i];
            //std::cout << n << " " << i << std::endl;
        }
        else
        {
            result = 1;
            n = i+1;
        }
    }

    return count;
}


int main()
{
    /*
    {
        std::array<std::int64_t, 4> values {1, 2, 3, 4};
        std::int64_t K = 10;
        std::int64_t result = Solve(values.data(), values.size(), K);
        std::cout << result << std::endl;
    }

    {
        std::array<std::int64_t, 7> values {1, 9, 2, 8, 6, 4, 3};
        std::int64_t K = 100;
        std::int64_t result = Solve(values.data(), values.size(), K);
        std::cout << result << std::endl;
    }
     */

    std::int64_t T, N, K;
    std::cin >> T;
    for (std::int64_t t=0; t<T; ++t)
    {
        std::cin >> N;
        std::cin >> K;
        std::vector<std::int64_t> values{};
        for (std::int64_t n=0; n<N; ++n)
        {
            std::int64_t value;
            std::cin >> value;
            values.push_back(value);
        }
        std::cout << Solve(values, N, K) << std::endl;
    }

    return 0;
}
