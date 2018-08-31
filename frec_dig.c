#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
	int main() {
	char n[]="0123456789";
	char c[1000];
	int a,b,co;
	scanf("%s",c);
	a=strlen(c);
	b=strlen(n);
	for(int j=0;j<b;j++)
	{
		co=0;
		for(int i=0;i<a;i++)
		{
			if(s[i]==n[j])
				co++;
		}
		printf("%d ",co);
		
	}
	return 0;
}
