#include <stdio.h>

int main(int argc, char *argv[]) {
	char ch;
	char s[20];
	char sen[100];
	scanf("%c %s",&ch,s);
	scanf("\n");
	scanf("%[^\n]%*c", sen);
	printf("%c\n%s\n%s",ch,s,sen);
	return 0;
}
