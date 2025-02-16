#include<iostream>
using namespace std;
template <class GenericType> 
GenericType add(GenericType a, GenericType b)
{
    return (a>b)? a-b : a+b;
}
int main ()
{
    int a,b;
    cin>>a>>b;
    cout<<add <float> (a, b);
}