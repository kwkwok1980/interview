//https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/

#include <iostream>
#include <array>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <stack>

std::stack<int> Solve(std::stack<int> input)
{
    std::stack<int> output{};
    while(!input.empty())
    {
        int value = input.top();
        input.pop();

        while(!output.empty() && output.top()<value)
        {
            input.push(output.top());
            output.pop();
        }

        output.push(value);

        while (!input.empty() && input.top() < output.top())
        {
            output.push(input.top());
            input.pop();
        }
    }
    return output;
}

int main()
{
    {
        std::stack<int> input;
        input.push(34);
        input.push(3);
        input.push(31);
        input.push(98);
        input.push(92);
        input.push(23);

        std::stack<int> output = Solve(input);
        while (!output.empty())
        {
            std::cout << output.top() << std::endl;
            output.pop();
        }
    }

    return 0;
}
