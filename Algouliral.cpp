#include<stdio.h>
#include<random>
int main ()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    for(int i=0; i<n ; i++)
    {
        for(int j=0; j<n ; j++)
        {
            a[i][j]=rand()%10;
        }
    }
    for(int i=0; i<n ; i++)
    {
        for(int j=0; j<n ; j++)
        {
            if(j<=i)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
                
        }
        printf("\n");
    }
}