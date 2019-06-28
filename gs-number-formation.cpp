//https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number/0
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <fstream>
#include <queue>
#include <stack>
#include <cmath>

const std::int64_t SIZE = 100 + 1;
std::int64_t NA = -1;
std::int64_t MOD = static_cast<std::int64_t>(std::pow(10, 9)) + 7;
std::int64_t sums[SIZE][SIZE][SIZE]{};
std::int64_t counts[SIZE][SIZE][SIZE]{};

std::int64_t SolveInternal1(std::int64_t value, std::int64_t X, std::int64_t Y, std::int64_t Z)
{
    std::int64_t sum = 0;

    if (X > 0)
    {
        std::int64_t valueX = (value * 10 + 4) % MOD;
        //std::cout << valueX << std::endl;
        sum = (sum + valueX + SolveInternal1(valueX, X - 1, Y, Z)) % MOD;
    }

    if (Y > 0)
    {
        std::int64_t valueY = (value * 10 + 5) % MOD;
        //std::cout << valueY << std::endl;
        sum = (sum + valueY + SolveInternal1(valueY, X, Y - 1, Z)) % MOD;
    }

    if (Z > 0)
    {
        std::int64_t valueZ = (value * 10 + 6) % MOD;
        //std::cout << valueZ << std::endl;
        sum = (sum + valueZ + SolveInternal1(valueZ, X, Y, Z - 1)) % MOD;
    }

    return sum;
}

void Solve1(std::int64_t X, std::int64_t Y, std::int64_t Z)
{
    std::int64_t sum = SolveInternal1(0, X, Y, Z);
    std::cout << sum << std::endl;
}

std::int64_t SolveInternal2(std::int64_t X, std::int64_t Y, std::int64_t Z)
{
    auto& sum = sums[X][Y][Z];
    auto& count = counts[X][Y][Z];

    if (X == 0 && Y == 0 && Z == 0)
    {
        count = 0;
        sum = 0;
    }
    else if (X == 1 && Y == 0 && Z == 0)
    {
        count = 1;
        sum = 4;
    }
    else if (X == 0 && Y == 1 && Z == 0)
    {
        count = 1;
        sum = 5;
    }
    else if (X == 0 && Y == 0 && Z == 1)
    {
        count = 1;
        sum = 6;
    }
    else
    {
        auto calculate = [&](std::int64_t i, std::int64_t j, std::int64_t k, std::int64_t value)
        {
            std::int64_t gg = (sums[i][j][k] * 10 % MOD + counts[i][j][k] * value % MOD) % MOD;
            //std::cout << gg << std::endl;
            sum = (sum + gg) % MOD;
            count = (count + counts[i][j][k]) % MOD;
        };

        if (X > 0)
        {
            calculate(X-1, Y, Z, 4);
        }

        if (Y > 0)
        {
            calculate(X, Y-1, Z, 5);
        }

        if (Z > 0)
        {
            calculate(X, Y, Z-1, 6);
        }
    }

    //std::cout << X << " " << Y << " " << Z << " " << sum << " " << count << std::endl;
    return sum;
}


void Solve2(std::int64_t X, std::int64_t Y, std::int64_t Z)
{
    for (std::int64_t i=0; i<=X; ++i)
    {
        for (std::int64_t j=0; j<=Y; ++j)
        {
            for (std::int64_t k=0; k<=Z; ++k)
            {
                sums[i][j][k] = 0;
                counts[i][j][k] = 0;
                SolveInternal2(i,j,k);
            }
        }
    }

    std::int64_t sum = 0;
    for (std::int64_t i=0; i<=X; ++i)
    {
        for (std::int64_t j=0; j<=Y; ++j)
        {
            for (std::int64_t k=0; k<=Z; ++k)
            {
                //std::cout << i << " " << j << " " << k << " " << result[i][j][k] << std::endl;
                sum = (sum + sums[i][j][k]) % MOD;
            }
        }
    }

    std::cout << sum << std::endl;
}

int main()
{
    std::int64_t T = 0;
    std::int64_t X = 0;
    std::int64_t Y = 0;
    std::int64_t Z = 0;

    std::cin >> T;
    for (std::int64_t t=0; t<T; ++t)
    {
        std::cin >> X;
        std::cin >> Y;
        std::cin >> Z;
        //Solve1(X, Y, Z);
        Solve2(X, Y, Z);
    }
}
