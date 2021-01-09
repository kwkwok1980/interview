//https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/

//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

void Solve(const std::string& input)
{
    std::vector<std::pair<int,int>> points{};
    int point = -1;
    int size = 0;

    for (int i=0; i<input.size(); ++i)
    {
        char c = input[i];
        if (c == 'I')
        {
            if (point != -1)
            {
                points.emplace_back(point, size);
                point = -1;
                size = 0;
            }
        }
        else
        {
            if (point != -1)
            {
                ++size;
            }
            else
            {
                point = i;
                size = 2;
            }
        }
    }

    if (point != -1)
    {
        points.emplace_back(point, size);
    }

    std::vector<int> results(input.size()+1);
    for (int i=0; i<input.size()+1; ++i)
    {
        results[i] = i+1;
    }

    for (auto [point, size] : points)
    {
        for (int i=0; i < size/2; ++i)
        {
            int tmp = results[point + size - 1 - i];
            results[point + size -1 - i] = results[point + i];
            results[point + i] = tmp;
        }
    }

    for (auto result : results)
    {
        std::cout << result;
    }
    std::cout << std::endl;
}

int main()
{
    std::string inputs[] = {"D", "I", "DD", "II", "DIDI", "IIDDD", "DDIDDIID"};
    for(const std::string& input : inputs)
    {
        Solve(input);
    }
    return 0;
}
