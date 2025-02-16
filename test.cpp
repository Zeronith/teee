#include<stdio.h>
#include <iostream>
using namespace std;
int sum(int a, int b)
{
    int c=a+b;
    return c;
}
int mins(int a, int b)
{
    int d =a-b;
    return d; 
}
int multi(int a, int b)
{
    int e = a*b;
    return e;
}
int divide(int a, int b)
{
    int f = a/b;
    return f;
}
void calculator()
{
    int hariu;
    while(1)
    {
        int a, b;
        cin>>a>>b; 
        cout<<"Ymr uildel hiih ve ?"<<endl; 
        char c;
        cin>>c; 
        if(c == '+') // Хэрэглэгчийн оруулсан тэмдэгт нь нэмэх эсэхийг шалгаж байна 
        {
            hariu = sum(a, b); // sum функцийг ажиллуулж буцаасан утгийг Niilber хувьсагчид оноов .
        }
        else if (c == '-')
        {
            hariu = mins(a, b);
        }
        else if (c == '*')
        {
            hariu = multi(a, b);
        }
        else if (c == '/')
        {
            hariu = divide(a, b);
        }
        else if(c == 'E')
        {
            break;
        }
        cout<<hariu<<endl;
    }   
}
int main ()
{
    
    calculator();
}