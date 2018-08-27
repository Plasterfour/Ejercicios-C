#include <stdio.h>
int main() 
{
	int n,i,j,m;
	scanf("%d", &n);
	int a = n*2 - 1;
	for(i=0;i<a;i++){
		for(j=0;j<a;j++){
			m = i < j ? i : j;
			m = m < a-i ? m : a-i-1;
			m = m < a-j-1 ? m : a-j-1;
			printf("%d ", n-m);
		}
		printf("\n");
	}
	return 0;
}
