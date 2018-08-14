#include <stdio.h>

int main(int argc, char *argv[]) {
	int i,a[10];
	int b;
	scanf("%i",&b);
	for(i=0;i<b;i++){
	scanf("%i",&a[i]);
	}
	for(i=b-1;i>=0;i--){
	printf("%i",a[i]);
	}
	return 0;
}

