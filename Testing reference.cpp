#include<iostream>
using namespace std;
int main ()
{
	int num;
	cin>>num;
	int &counter=num; // Counter is reference of num . 
	//So counter is just another name of num . They share same memory address .
	//Declaring it is looks pretty weird but except for declaring it other assigning value's are same as normal variable.
}