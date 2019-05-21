//https://practice.geeksforgeeks.org/problems/k-anagrams-1/0

#include <stack>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iterator>

void Solve(const std::vector<std::string>& values)
{
    std::unordered_map<std::string, int> valuesMap{};
    for (std::string value : values)
    {
        std::sort(value.begin(), value.end());
        ++valuesMap[value];
    }

    std::vector<int> counts{};
    counts.reserve(valuesMap.size());
    for (auto& pair : valuesMap)
    {
        counts.emplace_back(pair.second);
    }
    std::sort(counts.begin(), counts.end());
    std::copy(counts.begin(), counts.end(), std::ostream_iterator<int>{std::cout, " "});
    std::cout << std::endl;
}

int main() {

  int N=0, T =0;
  std::cin >> T;
  for(int t=0; t<T; ++t)
  {
      std::cin >> N;
      std::vector<std::string> values{};
      for (int n=0; n<N; ++n)
      {
          std::string value{};
          std::cin >> value;
          values.emplace_back(value);
      }
      Solve(values);
  }
}
