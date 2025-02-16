	#include<iostream>
#include<vector>
using namespace std;
void swap(int n, int m)
{
	int temp;
	temp=n;
	n=m;
	m=temp;
}
int main ()
{
	vector<int> tsuvaa;
	int a, n;
	cin>>n;
	for(int i=0; i<n ; i++)
	{
		cin>>a;
		tsuvaa.push_back(a);
	}
	int count=0, tooluur=1;
	for(int i=1; i<tsuvaa.size(); i++)
	{
		for(int j=i-1; j>=0 ; j--)
		{
			if(tsuvaa[i]==tsuvaa[j])
			{
				count++;
			}
		}

		if(count==0)
		{
			int temp=tsuvaa[i];
			tsuvaa[i]=tsuvaa[tooluur];
			tsuvaa[tooluur]=temp;
			tooluur++;
		}
		count=0;
	}
	for(int i=0 ; i<tooluur; i++)
	{
		cout<<tsuvaa[i]<<" ";
	}
}