// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1?page=1&company=Goldman%20Sachs&sortBy=submissions

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>
#include <tuple>
#include <ranges>
#include <charconv>
#include <cmath>
#include <memory_resource>
#include <set>
#include <map>

struct Node {
    int value = 0;
    int index = 0;
};

bool operator<(const Node& lhs, const Node& rhs) {
    if (lhs.value == rhs.value) {
        return lhs.index < rhs.index;
    } else {
        return lhs.value < rhs.value;
    }
}

int maxWater(std::vector<int>& values) {
    std::vector<Node> nodes{};
    int N = values.size();
    for (int i=0; i<N; ++i) {
        nodes.emplace_back(Node{values[i], i});
    }
    std::sort(nodes.begin(), nodes.end());
    std::reverse(nodes.begin(), nodes.end());

    std::list<int> results{};
    results.emplace_back(nodes[0].index);
    for (int i=1; i<N; ++i) {
        const Node& node = nodes[i];
        if (node.index > results.back()) {
            results.emplace_back(node.index);
        }
        if (node.index < results.front()) {
            results.emplace_front(node.index);
        }
    }
    int result = 0;
    for (auto it1 = results.begin(); it1 != results.end(); ++it1) {
        int x = *it1;
        auto it2 = std::next(it1);
        if (it2 != results.end()) {
            int y = *it2;
            int height = std::min(values[x], values[y]);
            for (int i=x; i<=y; ++i) {
                int value = values[i];
                if (height > value) {
                    result = result + (height - value);
                }
            }
        }
    }
    return result;
}

int main() {
    {
        std::vector values {3, 0, 1, 0, 4, 0, 2};
        std::cout << maxWater(values) << std::endl;
    }
    {
        std::vector values {1, 2, 3, 4};
        std::cout << maxWater(values) << std::endl;
    }
    {
        std::vector values {2, 1, 5, 3, 1, 0, 4};
        std::cout << maxWater(values) << std::endl;
    }

}

