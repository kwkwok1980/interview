#include <iostream>

void Solve(std::string& value)
{
    bool flag = false;
    for (char v : value)
    {
        if (flag)
        {
            switch(v)
            {
                case 'a':
                {
                    std::cout << 'a';
                    break;
                }
                case 'b':
                {
                    flag = false;
                    std::cout << 'a';
                    break;
                }
                case 'c':
                {
                    flag = false;
                    break;
                }
                default:
                {
                    flag = false;
                    std::cout << 'a' << v;
                    break;
                }
            }
        }
        else
        {
            switch (v)
            {
                case 'a':
                {
                    flag = true;
                    break;
                }
                case 'b':
                {
                    break;
                }
                default:
                {
                    std::cout << v;
                    break;
                }
            }
        }
    }
    
    if (flag)
    {
        std::cout << 'a';
    }
    std::cout << std::endl;
}

int main()
{
    int T{};
    std::cin >> T;
    for (int t=0; t<T; ++t) {
        std::string value{};
        std::cin >> value;
        //std::cout << text << std::endl;
        Solve(value);
    }
    return 0;
}
