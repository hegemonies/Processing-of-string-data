#include <stdio.h>
#include "strings.h"
//#include <string.h>

int main(void)
{
	/*
	char str[] = "This;is.a:test:of=the/string\\tokenizer-function.";
	printf("\n%s\n", str);
	char *str_tmp;
	//str_tmp = stok(str, " ");
	for (str_tmp = stok(str, "\\./:;=-"); str_tmp != NULL; str_tmp = stok(NULL, "\\./:;=-")) {
		printf("\n%s\n", str_tmp);
	}
	*/
	char str[] = "abd";
	char strc[20];
	scpy(strc, str);
	printf("%s\n", strc);
}
