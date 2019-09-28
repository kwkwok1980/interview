#include <iostream>
#include <unordered_set>

bool SolveInternal(const std::unordered_set<std::string>& values, const std::string& target, int index)
{
    if (index == target.size())
    {
        return true;
    }

    for (int i=index; i<target.size(); ++i)
    {
        std::string value = target.substr(index, i-index+1);
        if (values.find(value) != values.end())
        {
            if (SolveInternal(values, target, i+1))
            {
                return true;
            }
        }
    }
    return false;
}


void Solve(const std::unordered_set<std::string>& values, const std::string& target)
{
    if (SolveInternal(values, target, 0))
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
}

int main() {
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::unordered_set<std::string> values{};
        for (int n=0; n<N; ++n)
        {
            std::string value{};
            std::cin >> value;
            values.emplace(value);
        }
        std::string target{};
        std::cin >> target;
        Solve(values, target);
    }

    //codet
    return 0;
}
