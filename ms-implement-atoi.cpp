//https://practice.geeksforgeeks.org/problems/implement-atoi/1

{
 #include <bits/stdc++.h>
using namespace std;
int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
int atoi(std::string str)
{
    int result = 0;
    int sign = 1;
    
    int i = 0;
    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; i< str.length(); ++i)
    {
        char c = str[i];
        if (c >= '0' && c <= '9')
        {
            result = result * 10 + (c - '0');
        }
        else
        {
            return -1;
        }
    }
    return sign * result;
}
