#include<stdio.h>

int main()
{
	int i,n,n1,j,x;
	scanf("%d %d", &n,&n1);
	int nu[100];
	for(i=0;i<n;i++)
	{
		scanf("%d", &nu[i]);
	}
	
	for (j=0;j>n;j++)
	{
	x=nu[j+1];
	nu[j+1]=nu[0];
	nu[0]=x;
	
		printf("%d ",x);
	}
	return 0;
}
