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

void Solve(std::int64_t N)
{
   std::stringstream ss{};
   while (N != 0)
   {
       int M = (N % 26);
       if (M == 0)
       {
           ss << "Z";
           N = N / 26 - 1;
       }
       else
       {
           ss << static_cast<char>('A' + M - 1);
           N = N / 26;
       }
   }

   std::string s = ss.str();
   std::reverse(s.begin(), s.end());
   std::cout << s << std::endl;
}

int main()
{
    int T = 0;
    std::int64_t N = 0;

    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        Solve(N);
    }
}
