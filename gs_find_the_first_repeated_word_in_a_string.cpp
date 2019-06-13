//https://www.geeksforgeeks.org/find-first-repeated-word-string/

#include <iostream>
#include <array>
#include <sstream>
#include <unordered_map>
#include <vector>

std::string Solve(const std::string& value)
{
    std::stringstream ss{value};
    std::string token{};
    std::unordered_map<std::string, int> counts{};
    std::vector<std::string> tokens{};
    while(std::getline(ss, token, ' '))
    {
        if (!token.empty())
        {
            if (counts.find(token) == counts.end())
            {
                //std::cout << "cp 2 " << token << " "  << std::endl;
                counts.emplace(token, 1);
                tokens.emplace_back(token);
            }
            else
            {
                //std::cout << "cp 3 " << token << " "  << std::endl;
                counts[token] = counts[token] + 1;
            }
        }
    }

    for(const auto& t : tokens)
    {
        //std::cout << "cp 1 " << t << " " << counts[t] << std::endl;
        if (counts[t] > 1)
        {
            return t;
        }
    }

    return "No Repetition";
}


int main()
{
    {
        std::string value{"Ravi had been saying that he had been there"};
        std::string result = Solve(value);
        std::cout << result << std::endl;
    }

    {
        std::string value{"Ravi had been saying that"};
        std::string result = Solve(value);
        std::cout << result << std::endl;
    }

    {
        std::string value{"he had had he"};
        std::string result = Solve(value);
        std::cout << result << std::endl;
    }
    return 0;
}
