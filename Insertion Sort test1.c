#include<stdio.h>
int main ()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1; i<n; i++)
	{
		int temp=a[i], j;
		for(int j=i-1; j>=0 , temp<a[j]; j--)
		{
			a[j+1]=a[j];
		}
		a[j+2]=temp;
	}
	for(int i=0; i<n; i++)
	{
		printf("%d ",a[i]);
	}
}