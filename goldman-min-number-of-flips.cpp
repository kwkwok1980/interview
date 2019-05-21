//https://practice.geeksforgeeks.org/problems/min-number-of-flips/0

#include <stack>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>

int counts[2][1000];

void Solve(const std::string& values)
{
    for (int i=0; i<values.length(); ++i)
    {
        if (i == 0)
        {
            if (values[0] == '0')
            {
                counts[0][0] = 0;
                counts[1][0] = 1;
            }
            else
            {
                counts[0][0] = 1;
                counts[1][0] = 0;
            }
        }
        else
        {
            if (values[i] == '0')
            {
                counts[0][i] = counts[1][i-1];
                counts[1][i] = counts[0][i-1] + 1;
            }
            else
            {
                counts[0][i] = counts[1][i-1] + 1;
                counts[1][i] = counts[0][i-1];
            }
        }
        //std::cout << counts[0][i] << " " << counts[1][i] << std::endl;
    }
    std::cout << std::min(counts[0][values.length()-1], counts[1][values.length()-1]) << std::endl;
}

int main()
{

  int T=0;
  std::cin >> T;
  for(int t=0; t<T; ++t)
  {
      std::string values{};
      std::cin >> values;
      Solve(values);
  }
}
