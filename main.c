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
	int cc = 0;

	char *buf_path = malloc(sizeof(char) * slen(path) + 2);
	scpy(buf_path, path);
	buf_path[slen(path)] = *delim;
	buf_path[slen(path) + 1] = '\0';
	printf("buf_path ::: %s\n", buf_path);
	char *res = malloc(slen(path));//result str
	char *tmp;
	for (tmp = stok(buf_path, delim); tmp; tmp = stok(NULL, delim)) {
		if (slen(res)) {
			scat(res, delim);
		}
		cc++;
		printf("%s\n", tmp);
		char *buf = malloc(sizeof(char) *slen(tmp) + 2);
		scpy(buf, tmp);
		buf[slen(buf)] = '\\';
		buf[slen(buf) + 1] = 0;
		printf("buf : %s\n", buf);
		char *ttmp = sstr(buf, ":\\", slen(buf));
		if (ttmp) {//windows
			int n = ttmp - buf;
			printf("n == %d\n", n);
			//printf("tmp len: %d\n", slen(tmp));
			char *tr = malloc(sizeof(char) * (slen(buf) + 11));
			//printf("%d\n", slen(tr));
			scat(tr, "/cygdrive/");
			printf("tr :: %s\n", tr);
			if (n == 1) {
				tr[10] = (char)tolower(buf[0]);
				printf("tr :: %s\n", tr);
			} else if (n == 2) {
				tr[10] = (char)tolower(buf[0]);
				tr[11] = (char)tolower(buf[1]);
				printf("tr :: %s\n", tr);
			}
			char *tmp_t;
			printf("tmp :: %s\n", tmp);
			char *tmp_lt = save_static_char();
	//char *tmp_lt = lt;
	//printf("tmp_lt :: %s\nlt ::: %s\n", tmp_lt, lt);
			for (tmp_t = stok(buf + 3, "\\"); tmp_t; tmp_t = stok(NULL, "\\")) {
				printf("tmp_t :: %s\n", tmp_t);
				printf("tr :: %s\n", tr);
				scat(tr, "/");
				printf("tr :: %s\n", tr);
				scat(tr, tmp_t);
				printf("tr :: %s\n", tr);
			}
			new_static_char(tmp_lt);
	//lt = tmp_lt;
			printf("%s\n", tr);
			res = realloc(res, slen(res) + slen(tr));
			scat(res, tr);
			printf("res!!!: %s\n", res);
		} 
		else {//linux
			res = realloc(res, slen(res) + slen(tmp));
			scat(res, tmp);
		}
		
		//printf("%s\n", tmp);
	}
	//printf("%s\n", tmp);
	res[slen(res)] = 0;
	printf("cc == %d\n", cc);
	return res;
}

int main()
{
	/*
	char *path = malloc(sizeof(char) * MAX_PATH);
	char *delim = malloc(sizeof(char) * 3);

	input(path, delim);
	*/
	//check_input(check(path, delim));
	//char *res = process(path, delim);
	//printf("end res: %s\n", res);
	char path[] = "C:\\Windows\\system32+E:\\Distrib\\msoffice.exe+/home/alex/prog/lab4.c";
	//char path[] = "E:\\Distrib\\msoffice.exe+/home/alex/prog/lab4.c";
	//char path[] = "/home/alex/prog/lab4.c";
	char delim[] = "+";

	printf("delim: %s\npath: %s\n", delim, path);

	char *res = process(path, delim);
	printf("end res: %s\n", res);


	/*
	char *word;
	printf("\n%s\n\n", qq);
	for (tmp = stok(buf_path, delim); tmp; tmp = stok(NULL, delim))
	for (word = stok(qq, sep); word; word = stok(NULL, sep))
		printf("Next word is \"%s\".\n", word);
	*/
	return 0;
}
