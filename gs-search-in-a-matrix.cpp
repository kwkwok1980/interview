//https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1/
class Solution
{

public:
    bool search(std::vector<std::vector<int> > matrix, int N, int M, int K)
    {
        int n1 = 0;
        int n2 = N;
        int m1 = 0;
        int m2 = M;

        while (true)
        {
            int nextn1 = -1;
            int nextn2 = -1;
            int nextm1 = -1;
            int nextm2 = -1;

            for (int i=n1; i<n2; ++i)
            {
                if (matrix[i][m1] <= K && K <= matrix[i][m2-1])
                {
                    nextn1 = i;
                    break;
                }
            }

            for (int i=n2; i>n1; --i)
            {
                if (matrix[i-1][m1] <= K && K <= matrix[i-1][m2-1])
                {
                    nextn2 = i;
                    break;
                }
            }

            if (nextn1 == -1 || nextn2 == -1)
            {
                return false;
            }

            for (int i=m1; i<m2; ++i)
            {
                if (matrix[n1][i] <= K && K <= matrix[n2-1][i])
                {
                    nextm1 = i;
                    break;
                }
            }

            for (int i=m2; i>m1; --i)
            {
                if (matrix[n1][i-1] <= K && K <= matrix[n2-1][i-1])
                {
                    nextm2 = i;
                    break;
                }
            }

            if (nextm1 == -1 || nextm2 == -1)
            {
                return false;
            }

            //std::cout << nextn1 << " " << nextn2 << " " << nextm1 << " " << nextm2 << std::endl;

            if (n1 == nextn1 && n2 == nextn2 && m1 == nextm1 && m2 == nextm2)
            {
                break;
            }
            else
            {
                n1 = nextn1;
                n2 = nextn2;
                m1 = nextm1;
                m2 = nextm2;
            }
        }

        for (int i=n1; i<n2; ++i)
        {
            for (int j=m1; j<m2; ++j)
            {
                if (matrix[i][j] == K)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    std::vector<std::vector<int>> matrix {};

    matrix.push_back({1,2,2,5,5,6});
    matrix.push_back({6,6,6,7,8,8});
    matrix.push_back({9,10,11,11,12,12});
    matrix.push_back({12,13,14,14,14,17});
    matrix.push_back({19,20,21,21,22,22});
    matrix.push_back({23,23,23,23,23,25});
    matrix.push_back({25,25,26,27,27,28});
    matrix.push_back({29,29,31,31,31,32});
    matrix.push_back({34,37,37,37,37,38});
    matrix.push_back({40,40,41,41,41,41});
    matrix.push_back({43,43,43,43,44,45});
    matrix.push_back({45,46,47,49,49,51});
    matrix.push_back({51,51,53,55,56,56});
    matrix.push_back({57,59,59,60,60,61});
    matrix.push_back({62,63,64,65,66,67});
    matrix.push_back({68,69,69,69,70,70});
    matrix.push_back({72,73,73,73,73,74});
    matrix.push_back({74,77,79,80,80,82});
    matrix.push_back({82,82,83,83,85,85});
    matrix.push_back({85,85,86,87,88,88});
    matrix.push_back({91,91,91,91,93,95});
    matrix.push_back({96,97,97,98,99,99});
    matrix.push_back({100,100,100,100,100,100});

    Solution solution{};
    std::cout << std::boolalpha << solution.search(matrix, 23, 6, 25) << std::endl;
}
