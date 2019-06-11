//https://www.geeksforgeeks.org/maximum-product-subarray/

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

void Solve(int* values, int N)
{
    std::int64_t results[N];

    results[0] = values[0];
    std::int64_t max = results[0];

    for (int i=1; i<N; ++i)
    {
        if (results[i-1] != 0)
        {
            results[i] = results[i-1] * values[i];
        }
        else
        {
            results[i] = values[i];
        }
        max = std::max(results[i], max);
    }

    for (int i=1; i<N; ++i)
    {
        if (values[i-1] == 0)
        {
            continue;
        }

        for (int j=i; j<N; ++j)
        {
            if (values[j] == 0)
            {
                break;
            }
            results[j] = results[j] / values[i-1];
            max = std::max(max, results[j]);
        }
    }

    std::cout << max << std::endl;
}


std::int64_t SolveInternal(int* values, int start, int end)
{
    if (end - start == 1)
    {
        return values[start];
    }

    std::int64_t max = std::numeric_limits<std::int64_t>::min();

    std::int64_t value1 = 1;
    for (int i=start; i<end; ++i)
    {
        value1 *= values[i];
    }

    if (value1 > 0)
    {
        return value1;
    }

    std::int64_t value2 = 1;
    for (int i=start; i<end; ++i)
    {
        if (values[i] > 0)
        {
            value2 *= values[i];
        }
        else
        {
            max = std::max(max, value2);
            max = std::max(max, value1 / (value2 * values[i]));
            break;
        }
    }

    std::int64_t value3 = 1;
    for (int i=end-1; i>=0; --i)
    {
        if (values[i] > 0)
        {
            value3 *= values[i];
        }
        else
        {
            max = std::max(max, value3);
            max = std::max(max, value1/(value3* values[i]));
            break;
        }
    }

    return max;
}

void Solve2(int* values, int N)
{
    int start = 0;
    int end = 0;
    std::int64_t max = std::numeric_limits<std::int64_t>::min();

    while (start < N)
    {
        while (end <N && values[end] != 0)
        {
            ++end;
        }

        if (start != end)
        {
            max = std::max(max, SolveInternal(values, start, end));
        }

        if (end < N)
        {
            max = std::max(max, static_cast<std::int64_t >(0));
        }

        start = end + 1;
        end = end +1;
    }

    std::cout << max << std::endl;
}


void Solve3(int* values, int N)
{
    std::int64_t product_pos = 0;
    std::int64_t product_neg = 0;
    std::int64_t max = std::numeric_limits<std::int64_t>::min();
    for (int i=0; i<N; ++i)
    {
        if (values[i] > 0)
        {
            if (product_pos != 0)
            {
                product_pos *= values[i];
                max = std::max(max, product_pos);
            }
            else
            {
                product_pos = values[i];
                max = std::max(max, product_pos);
            }

            if (product_neg != 0)
            {
                product_neg *= values[i];
                max = std::max(max, product_neg);
            }
            else
            {
                product_neg = 0;
            }
        }
        else if (values[i] == 0)
        {
            product_pos = 0;
            product_neg = 0;
            max = std::max(max, static_cast<std::int64_t >(0));
        }
        else
        {
            std::int64_t temp = product_pos;
            if (product_neg != 0)
            {
                product_pos = product_neg * values[i];
                max = std::max(max, product_pos);
            }
            else
            {
                product_pos = 0;
            }

            if (temp != 0)
            {
                product_neg = temp * values[i];
                max = std::max(max, product_neg);
            }
            else
            {
                product_neg = values[i];
                max = std::max(max, product_neg);
            }
        }
    }
    std::cout << max << std::endl;
}

void Solve4(int values[], int N)
{
    long long product_pos = 1;
    long long product_neg = 1;
    long long max = std::numeric_limits<long long>::min();
    for (int i=0; i<N; ++i)
    {
        if (values[i] > 0)
        {
            product_pos = product_pos * values[i];
            max = std::max(max, product_pos);
            if (product_neg != 1)
            {
                product_neg = product_neg * values[i];
            }
        }
        else if(values[i] < 0)
        {
            long long temp_pos = 1;
            if (product_neg != 1)
            {
                temp_pos = product_neg * values[i];
                max = std::max(max, temp_pos);
            }

            long long temp_neg = product_pos * values[i];
            max = std::max(max, temp_neg);

            product_pos = temp_pos;
            product_neg = temp_neg;
        }
        else
        {
            product_pos = 1;
            product_neg = 1;
            max = std::max(max, 0LL);
        }
    }
    std::cout << max << std::endl;
}

int main()
{
    //std::cout << std::numeric_limits<std::int64_t>::max() << std::endl;
    //return 0;
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        int values[N];
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }
        Solve4(values, N);
    }
    return 0;
}

