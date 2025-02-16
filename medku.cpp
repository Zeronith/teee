#include<iostream>
using namespace std;
int main ()
{
	int count =0;
	/* 2, 5, 10, 25 100  */
	for(int i=0 ; i<=50; i++)
	{
		for(int j =0 ; j<=20 ; j++)
		{
			for(int k=0; k<=10; k++)
			{
				for(int p=0; p<=4; p++)
				{
					if(i*2+j*5+k*10+p*25==100)
					{
						cout<<i*2<<" "<<j*5<<" "<<k*10<<" "<<p*25<<endl;
						count++;
					}
				}
			}
		}
	}
	cout<<count;
}