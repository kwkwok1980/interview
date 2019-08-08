//https://practice.geeksforgeeks.org/problems/run-length-encoding/1

{
#include <bits/stdc++.h>
using namespace std;
char *encode(char *src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		char str[10000];
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function */

#include <sstream>

char *encode(char *src)
{
    std::stringstream buffer{};
    int begin = 0;
    int end = 0;
    while(src[end] != 0)
    {
        while(src[begin] == src[end])
        {
            ++end;
        }
        buffer << src[begin] << (end - begin);
        begin = end;
    }
    
    std::string result = buffer.str(); 
    strcpy(src, result.c_str());
    return src;
}
