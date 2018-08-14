#include <stdio.h>

int main() {
	int n;
	char no[5];
	scanf("%s", no);
	int sum = 0;
	for(int i = 0 ; i < 5 ; i++)
	sum += no[i] - '0';
	printf("%d",sum);
	return 0;
}
