#include <iostream>

void Solve(const std::string& value)
{
    int index[26]{};
    for (char c : value)
    {
        if (index[c-'a'] == 0)
        {
            index[c-'a'] = 1;
        }
        else if (index[c-'a'] == 1)
        {
            index[c-'a'] = 2;
        }
    }
    
    for (char c : value)
    {
        if (index[c-'a'] == 2)
        {
            std::cout << c << std::endl;
            return;
        }
    }
    
    std::cout << -1 << std::endl;
}

int main() {
	int T = 0;
	std::cin >> T;
	std::string value{};
	for (int t=0; t<T; ++t)
	{
	    std::cin >> value;
	    Solve(value);
	}
	//code
	return 0;
}
