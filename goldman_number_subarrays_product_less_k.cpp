//https://www.geeksforgeeks.org/number-subarrays-product-less-k/

#include <iostream>
#include <array>

int Solve(const int* values, int N, int K)
{
    int result = 1;
    int count = 0;
    int n = 0;

    for (int i=0; i<N; ++i)
    {
        for (int j=n; j<N; ++j)
        {
            if (result * values[j] > K)
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
    {
        std::array<int, 4> values {1, 2, 3, 4};
        int K = 10;
        int result = Solve(values.data(), values.size(), K);
        std::cout << result << std::endl;
    }

    {
        std::array<int, 7> values {1, 9, 2, 8, 6, 4, 3};
        int K = 100;
        int result = Solve(values.data(), values.size(), K);
        std::cout << result << std::endl;
    }

    return 0;
}
