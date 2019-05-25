//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

#include <algorithm>
#include <cstring>

/*Function to reverse words*/
void reverseWords(char *start) {
    int N = strlen(start);
    char* end = start+N;
    std::reverse(start, end);
    char* i=start;
    char* j=start;
    while (i!=end)
    {
        while(j!=end && *j != '.')
        {
            ++j;
        }
        std::reverse(i, j);
        if (j!=end)
        {
            i = ++j;
        }
        else
        {
            break;
        }
    }
    std::cout << start << std::endl;
}

int main() {
    int T = 0;
    int N = 0;
    int M = 0;
    int X = 0;
    char buffer[1000];
    std::cin >> buffer;
    reverseWords(buffer);

}
