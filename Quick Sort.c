#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void less( int *a, int *b)
{
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
	{
		return -1;
	}
	else 
	{
		return 0;
	}
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void knuth_shuffle(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);   
    }
}
void partition(int a[], int lo, int hi)
{
	int pivot=a[lo];
	int j=lo;
	int i=hi+1;
	while(1)
	{
		while(less(&a[++j], &pivot)==-1)
		{
			if(j==hi)
			{
				break;
			}
		}
		while(less(a[--i], &pivot)==1)
		{
			if(i==lo)
			{
				break;
			}
		}
		if(j>=i)
		{
			break;
		}
		swap(&a[i], &a[j]);
	}
	swap(lo, a[i]);
	return j;
}
void quicksort(int a, int lo, int hi)
{
	if(hi<=lo)
	{
		return;
	}
	int j=partition(a, lo, hi);
	quicksort(a, lo, j-1);
	quicksort(a, j+1, hi);
}
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    srand(time(0));  

    int n;
    scanf("%d", &n);
    int *a=(malloc(sizeof(int)*n));
    for(int i=0; i<n; i++)
    {
    	scanf("%d",&a[i]);
	}
    knuth_shuffle(a, n);
    quicksort(&a, &lo, &hi);
    for(int i=0; i<n; i++)
    {
    	printf("%d ", a[i]);
	}
    return 0;
}
