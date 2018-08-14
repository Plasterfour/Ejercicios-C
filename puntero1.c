#include <stdio.h>

int main(int argc, char *argv[]) {
	int a,b,c,d;
	int *p1,*p2;
	scanf("%i\n%i",&a,&b);
	c=a+b;
	d=b-a;
	p1=&c;
	p2=&d;
	printf("%i\n%i",*p1,*p2);
	return 0;
}
