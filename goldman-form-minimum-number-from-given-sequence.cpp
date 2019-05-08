//https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/

#include <iostream>
#include <array>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <stack>

void Solve(const std::string& input)
{
    int* output = new int[input.length()+1]{};
    output[0] = 1;
    int max = 1;
    for (int i=0; i<input.length(); ++i)
    {
        if (input[i] == 'I')
        {
            output[i+1] = ++max;
        }
        else
        {
            output[i+1] = output[i];
            for (int j=i; j>=0; --j)
            {
                if (input[j] == 'D')
                {
                    ++output[j];
                    max = std::max(max, output[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }

    for (int i=0; i<input.length()+1; ++i)
    {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const char* inputs[] = {"D", "I", "DD", "II", "DIDI", "IIDDD", "DDIDDIID"};
    for(const char* input : inputs)
    {
        Solve(input);
    }
    return 0;
}
