//https://practice.geeksforgeeks.org/problems/merge-two-strings/0
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
#include <iostream>

void Solve(const std::string& value1, const std::string& value2)
{
    int N1 = value1.size();
    int N2 = value2.size();

    int n1 = 0;
    int n2 = 0;
    while (n1 < N1 || n2 < N2)
    {
        if (n1 < N1)
        {
            std::cout << value1[n1];
            ++n1;
        }

        if (n2 < N2)
        {
            std::cout << value2[n2];
            ++n2;
        }
    }
    std::cout << std::endl;
}

int main() {
    int T = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::string value1{};
        std::string value2{};

        std::cin >> value1;
        std::cin >> value2;

        Solve(value1, value2);
    }
    return 0;
}
