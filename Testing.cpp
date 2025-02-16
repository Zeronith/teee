#include<iostream>
using namespace std;

int main ()
{
    int num;
    cin>>num;
    int *gg=&num;
    int **gg1= &gg;
    cout<<gg1<<endl<<&gg<<endl<<endl;
    cout<<*gg1<<endl<<gg<<endl<<&num<<endl;
}