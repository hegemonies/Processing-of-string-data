#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

char *input(char *path)
{
	printf("path: ");
	scanf("%s", path);
	return path;
}

int main(int argc, char *argv[])
{
	char path[260];
	input(path);
	printf("%s :: %s\n", path, delim);
	return 0;
}
