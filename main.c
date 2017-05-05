#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

#define MAX_PATH 260

void input(char *path, char *delim)
{
	printf("delim: ");
	scanf("%s", delim);
	printf("path: ");
	scanf("%s", path);
	printf("\n");
}
/*
int check(char *path)
{
	if (sspn(path, "*?\"<>|")) {
		return 1;
	}
	char *result = sstr(path, ":\\");
	if (result != NULL) {
		//if (result - path >= 1 || result - path <= 2) {
		if (result - path > 0) {
			int num_char = 0;
			for (int k = result - path; k >= 0; k--) {
				if (isalpha(path[k])) {
					num_char++;
				}
			}
			if (num_char == result - path) {
				if (sstr(path, "/") == 0) {
					return 0;
				}
			}
		}
	} else {
		if (sspn(path, "\\") == 0) {
			return 0;
		}
	}
	return 1;
}
*/
int check(char *path, char *delim)
{
	char *str_tmp;
	for (str_tmp = stok(str, delim); str_tmp != NULL; str_tmp = stok(NULL, delim)) {
		if (slen(path) >= MAX_PATH) {//len?
			return 3;
		}
		char *ch = sstr(path, ":\\"); //windows?
		if (ch - path) {
			if (sspn(path, "*?<\">/|")) {
				return 1;
			}
			if ((ch = sstr(path, ":"))) {
				if (ch[1] != 92) {//92 == "\\"
					return 1;
				}
			}
		} else if (((ch = sstr(path, "/")) - path) >= 0) {//linux?
			if (sspn(path, "*?:\\<\">|")) {
				return 2;
			}
		}
		return 0;
	}	
}

// 0 - good, 1 - trable windows, 2 - trable linux, 3 - problam with len of path
void check_input(int n)
{
	switch (n) {
		case 1:
			printf("Problem in the way Windows.\n");
			break;
		case 2:
			printf("Problem in the way Linux.\n");
			break;
		case 3:
			printf("Length too long.\n");
			break;
	}
}

int main()
{
	char *path = malloc(sizeof(char) * MAX_PATH);
	char *delim = malloc(sizeof(char) * 3);

	input(path, delim);
	check_input(check(path));
	return 0;
}
