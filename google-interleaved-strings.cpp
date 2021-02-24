//https://practice.geeksforgeeks.org/problems/interleaved-strings/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <list>
#include <mutex>
#include <atomic>
#include <memory>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <c++/8/sstream>
#include <ranges>

int TRUE = 1;
int FALSE = -1;
int UNKNOWN = 0;
int result[100+1][100+1]{};

int Solve(const std::string& A, const std::string& B, const std::string& C, int i, int j)
{
    if (result[i][j] != UNKNOWN)
    {
        return result[i][j];
    }

    if (i == A.size() && j == B.size())
    {
        result[i][j] = TRUE;
        return TRUE;
    }

    if (i < A.size())
    {
        if (A[i] == C[i+j])
        {
            if (Solve(A, B, C, i+1, j) == TRUE)
            {
                result[i][j] = TRUE;
                return TRUE;
            }
        }
    }

    if (j < B.size())
    {
        if (B[j] == C[i+j])
        {
            if (Solve(A, B, C, i, j+1) == TRUE)
            {
                result[i][j] = TRUE;
                return TRUE;
            }
        }
    }

    result[i][j] = FALSE;
    return FALSE;
}

bool isInterleave(std::string A, std::string B, std::string C)
{
    for (int i=0; i<100+1; ++i)
    {
        for (int j=0; j<100+1; ++j)
        {
            result[i][j] = UNKNOWN;
        }
    }

    return Solve(A, B, C, 0,0) == TRUE;
}

int main()
{
    std::string A = "aab";
    std::string B = "axy";
    std::string C = "aaxaby";
    std::cout << std::boolalpha << isInterleave(A, B, C) << std::endl;
}
