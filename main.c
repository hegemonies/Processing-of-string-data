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

int check(char *path, char *delim)
{
	char *str_tmp;
	for (str_tmp = stok(path, delim); str_tmp != NULL; str_tmp = stok(NULL, delim)) {
		printf("зашли :: 50\n");
		if (slen(path) >= MAX_PATH) {//len?
			printf("зашли :: 52\n");
			return 3;
		}
		printf("зашли :: 55\n");
		char *ch = sstr(path, ":\\", slen(path)); //windows?
		printf("%s\n", ch);
		if (ch - path) {
			printf("зашли :: 57\n");
			if (sspn(path, "*?<\">/|")) {
				printf("зашли :: 59\n");
				return 1;
			}
			printf("%s\n", ch = sstr(path, ":", slen(path)));
			if ((ch = sstr(path, ":", slen(path)))) {
				printf("%s\n", ch);
				printf("зашли :: 63\n");
				if (ch[1] != 92 && isalpha(ch - path)) {//92 == "\\"
					printf("зашли :: 65\n");
					return 1;
				}
			}
		} else if (((ch = sstr(path, "/", slen(path))) - path) >= 0) {//linux?
			printf("зашли :: 70\n");
			if (sspn(path, "*?:\\<\">|")) {
				printf("зашли :: 72\n");
				return 2;
			}
		}
	}	
	printf("зашли :: 77\n");
	return 0;
}

// 0 - good, 1 - trable windows, 2 - trable linux, 3 - problam with len of path
void check_input(int n)
{
	switch (n) {
		case 0:
			printf("OK\n");
			break;
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
*/

char *process(char *path, char *delim)
{
	char *res = malloc(slen(path));//result str
	char *tmp;
	for (tmp = stok(path, delim); tmp; tmp = stok(NULL, delim)) {
		//char *tmp = stok(path, delim);
		char *ttmp = sstr(tmp, ":\\", slen(tmp));
		if (ttmp) {//windows
			int n = ttmp - tmp;
			char *tr = malloc(sizeof(char) * (slen(tmp) - 1) + 11);
			scat(tr, "/cygdrive/");
			if (n == 1) {
				tr[10] = (char)tolower(tmp[0]);
			} else {
				tr[10] = (char)tolower(tmp[0]);
				tr[11] = (char)tolower(tmp[1]);
			}
			//scat(tr, (char)tolower(tmp[0]));
			//scat(tr, "/");
			char *tmp_t;
			for (tmp_t = stok(ttmp + 2, "\\"); tmp_t; tmp_t = stok(NULL, "\\")) {
				scat(tr, "/");
				scat(tr, tmp_t);
			}
			scat(tr, delim);
			res = realloc(res, sizeof(res) + slen(tr));
			scat(res, tr);
		} else {//linux
			res = realloc(res, sizeof(res) + slen(tmp));
			scat(res, tmp);
		}
	}
	return res;
}


int main()
{
	char *path = malloc(sizeof(char) * MAX_PATH);
	char *delim = malloc(sizeof(char) * 3);

	input(path, delim);
	//check_input(check(path, delim));
	char *res = process(path, delim);
	printf("%s\n", res);
	return 0;
}
