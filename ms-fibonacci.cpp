//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

template<int n>
struct Fibonacci
{
    static constexpr int value = Fibonacci<n-1>::value + Fibonacci<n-2>::value;
};

template<>
struct Fibonacci<0>
{
    static constexpr int value = 0;
};

template<>
struct Fibonacci<1>
{
    static constexpr int value = 1;
};

template<int N>
struct Fibonacci2
{
    static constexpr int CalculateValue()
    {
        if constexpr (N == 0)
        {
            return 0;
        }
        else if constexpr (N == 1)
        {
            return 1;
        }
        else
        {
            return Fibonacci2<N-1>::value + Fibonacci2<N-2>::value;
        }
    }

    static constexpr int value = CalculateValue();
};

int FibonacciCal(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    int value1 = 0;
    int value2 = 1;
    int value3 = 0;
    for (int i=2; i<=n; ++i)
    {
        value3 = value2 + value1;
        value1 = value2;
        value2 = value3;
    }

    return value3;
};

int main()
{
    std::cout << Fibonacci<0>::value << std::endl;
    std::cout << Fibonacci<1>::value << std::endl;
    std::cout << Fibonacci<2>::value << std::endl;
    std::cout << Fibonacci<10>::value << std::endl;

    std::cout << Fibonacci2<0>::value << std::endl;
    std::cout << Fibonacci2<1>::value << std::endl;
    std::cout << Fibonacci2<2>::value << std::endl;
    std::cout << Fibonacci2<10>::value << std::endl;

    std::cout << FibonacciCal(10) << std::endl;
}
