//https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
{
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/

int _stack :: getMin()
{
    if (!s.empty())
    {
        return s.top();
    }
    else
    {
        return -1;
    }
   //Your code here
}
/*returns poped element from stack*/
int _stack ::pop()
{
    if (!s.empty())
    {
        s.pop();
        int v = s.top();
        s.pop();
        return v;
    }
    else
    {
        return -1;
    }
    
   //Your code here
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if (!s.empty())
    {
        int m = std::min(s.top(), x);
        s.push(x);
        s.push(m);    
    }
    else
    {
        s.push(x);
        s.push(x);
    }
   //Your code here
}
