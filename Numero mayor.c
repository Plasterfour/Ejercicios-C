#include <stdio.h>
int ma(int a,int b,int c, int d);
int main(int argc, char *argv[]) {
	int a,b,c,d,e;
	scanf("%i %i %i %i",&a,&b,&c,&d);
	e= ma(a,b,c,d);
	printf("%i",e);
	return 0;
}
int ma(int a,int b,int c, int d){
	int mayor;
	if (a>d&&c&&b){
		mayor=a;
	}if(b>a&&c&&d){
		mayor=b;
	}if(c>b&&a&&d){
		mayor=c;
	}if (d>c&&b&&a){
		mayor=d;
	}
	return mayor;
}

