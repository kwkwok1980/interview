//https://practice.geeksforgeeks.org/problems/tower-of-hanoi/0
#include <iostream>
using namespace std;

int SolveInternal(int diskStart, int diskEnd, int fromRod, int toRod)
{
    if (diskStart == diskEnd)
    {
        std::cout << "move disk " << diskStart << " from rod " << fromRod << " to rod " << toRod << std::endl;
        return 1;
    }
    
    int middleRod = 1^2^3^fromRod^toRod;
    int step1 = SolveInternal(diskStart, diskEnd-1, fromRod, middleRod);
    int step2 = SolveInternal(diskEnd, diskEnd, fromRod, toRod);
    int step3 = SolveInternal(diskStart, diskEnd-1, middleRod, toRod);
    return step1 + step2 + step3;   
}

void Solve(int N)
{
   int step = SolveInternal(1, N, 1, 3);
   std::cout << step << std::endl;
}

int main() {
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        Solve(N);
    }
	//code
	return 0;
}
