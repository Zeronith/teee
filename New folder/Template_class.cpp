#include<iostream>
using namespace std;
template <class T>
class hoslol
{
private :
    T value[2];
public :
    hoslol(T first, T second)
    {
       value[0]= first;
       value[1]=second;
    }
    T getmax()
    {
return (this->value[0]>=this->value[1])?this->value[0]:this->value[1];
    }       

};
int main()
{
    hoslol <float> obj1(2.2, 1.3);
    cout<<obj1.getmax();
}
