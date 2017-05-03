#include <stdio.h>
#include <string.h>

int gg(char *str, char *strc)
{
	int ncount = 0, pcount = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] < strc[i]) {
			ncount++;
		} else if (str[i] > strc[i]) {
			pcount++;
		}
	}
	if (ncount < pcount) {
		return pcount;
	} else if (ncount > pcount) {
		return -ncount;
	}
	return 0;
}

int main(void)
{
	/*
	char str[] = "abd";
	char strc[] = "abc";
	
	printf("%d\n", gg(str, strc));
	*/
	printf("%d\n", strlen(" "));
}