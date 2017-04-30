#include <stdio.h>
#include "strings.h"

int main(void)
{
	char *str = "hello\n";
	int len = slen(str);
	printf("slen: %d\n", len);
}