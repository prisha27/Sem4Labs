#include<stdio.h>
#include<stdlib.h>
void insertionsort(int a[],int n)
{
	int v,i,j;
     for(i=1;i<n;i++)
     {
     	v=a[i];
     	j=i-1;
     	while(j>=0&&a[j]>v)
     	{
     		a[j+1]=a[j];
     		j=j-1;
     	}
     	a[j+1]=v;

     }

     for(i=0;i<n;i++)
	{
		printf("-> %d",a[i]);
	}
}
int main()
{
	int n,i;
	printf("enter size of array:");
	scanf("%d",&n);
	int a[n];
	printf("enter elements of array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertionsort(a,n);
	
	return 0;

}
