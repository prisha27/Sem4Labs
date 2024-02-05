#include<stdio.h>

void consecutive(int m1, int n1)
{
	int op=1;
	int t=(m1>n1)?n1:m1;
	while (t>0) 
	{
		if(m1%t==0)
		{
		 if (n1%t==0)
		
		{	
			printf("\n GCD of the two numbers is : %d \n",t);
	break;
}
}
    op++;
	t=t-1;
	}
	printf("count %d",op);
	
	
		
	
}

int main()
{
	int n,m;
	printf("\n enter two numbers whose GCD you want to find \n");
	scanf("%d",&m);
	scanf("%d",&n);
	
	consecutive(m,n);
	return 0;
}