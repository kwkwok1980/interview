//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
#include <iostream>


const std::size_t MAX = 501;
int values[MAX][MAX]{};

int getId(int values[MAX][MAX], int N)
{
    int results[MAX]{};
    for (int i=0; i<N; ++i)
    {
        if (results[i] == 1)
        {
            continue;
        }

        for (int j=0; j<N; ++j)
        {
            if (i == j)
            {
                continue;
            }

            if (values[i][j] == 1)
            {
                results[i] = 1;

                if (results[j] == 0)
                {
                    for (int k=0; k<N; ++k)
                    {
                        if (j == k)
                        {
                            continue;
                        }

                        if (values[k][j] == 0)
                        {
                            results[j] = 1;
                            break;
                        }
                    }

                    if (results[j] == 0)
                    {
                        for (int k=0; k<N; ++k)
                        {
                            if (j == k)
                            {
                                continue;
                            }

                            if (values[j][k] == 1)
                            {
                                results[j] = 1;
                                break;
                            }
                        }

                        if (results[j] == 0)
                        {
                            return j;
                        }
                    }
                }
            }
        }
    }

    return -1;
}

void Test(int values[])
{
    values[0] = 100;
    *(values+1) = 101;
}

int main()
{
    int values2[MAX]{};
    Test(values2);
    std::cout << values2[0] << std::endl;
    std::cout << values2[1] << std::endl;

    int T = 0;
    int N = 0;
    std::string S{};
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j)
            {
                std::cin >> values[i][j];
            }
        }
        getId(values, N);
    }
    return 0;
}
