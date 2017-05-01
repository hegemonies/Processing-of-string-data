#include <stdio.h>
#include "strings.h"

int main(void)
{
	char *str = "Hello World";
	//int len = slen(str);
	//printf("slen: %d\n", len);
	char *str_tmp;
	for (str_tmp = stok(str, " ");str_tmp; str_tmp = stok(NULL, " ")) {
		printf("%s\n", str_tmp);
	}
	
}