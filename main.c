#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

char *input(char *path)
{
	char tmp[260];
	printf("path: ");
	fgets(tmp, 260, stdin);
	printf("slen: %d\n", slen(tmp));
	path = realloc(path, slen(tmp));
	scpy(path, tmp);
	return path;
}

int main()
{
	char *path = malloc(sizeof(char*));
	path = input(path);
	printf("%s", path);
	return 0;
}
