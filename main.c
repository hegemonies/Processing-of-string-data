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

int check(char *path, char *delim)
{
	char *buf_path = malloc(sizeof(char) * slen(path) + 2);
	scat(buf_path, path);
	buf_path[slen(buf_path)] = *delim;
	buf_path[slen(buf_path)] = '\0';
	printf("buf_path :: %s\n", buf_path);
	char *str_tmp;
	for (str_tmp = stok(buf_path, delim); str_tmp; str_tmp = stok(NULL, delim)) {
		printf("%s\n", str_tmp);
		printf("зашли :: 56\n");
		if (slen(path) >= MAX_PATH) {//len?
			printf("зашли :: 57\n");
			return 3;
		}
		printf("зашли :: 60\n");
		char *th_wi_let = sstr(str_tmp, ":\\"); //windows?
		char *th_wi_nlet = sstr(str_tmp, "\\");
		//printf("%s\n", ch);

		if (th_wi_nlet) {
			if (!isalpha(str_tmp[0]) && str_tmp[0] != '\\') {
				printf("39\n");
				return 1;
			}
			if (sspn(str_tmp, "*?<\">,/|")) {
				printf("зашли :: 68\n");
				return 1;
			}
		}
		
		if ((th_wi_let - str_tmp == 1) || (th_wi_let - str_tmp == 2)) {
			printf("зашли :: 66\n");
			if (isalpha(str_tmp[0]) && str_tmp[1] == ':') {
				if (sspn(str_tmp, "*?<\">,/|")) {
					printf("зашли :: 38\n");
					return 1;
				}
			}
			if (sspn(str_tmp, "*?<\">,/|")) {
				printf("зашли :: 68\n");
				return 1;
			}
			//printf("%s\n", th_wi_let = sstr(path, ":"));
			if (th_wi_let - str_tmp == 1) {
				if (str_tmp[0] > 90) {
					printf("зашли :: 74\n");
					return 1;
				}
			} else if (th_wi_let - str_tmp == 2) {
				if (str_tmp[0] > 90 || str_tmp[1] > 90) {//проверка на заглавные буквы
					printf("зашли :: 78\n");
					return 1;
				}
			}
		} else if (((th_wi_let = sstr(str_tmp, "/")) - str_tmp) == 0) {//linux?
			printf("зашли :: 88\n");
			if (sspn(str_tmp, "*?:\\<\">,|")) {
				printf("зашли :: 90\n");
				return 2;
			}
		}
	}	
	printf("зашли :: 95\n");
	return 0;
}

// 0 - good, 1 - trable windows, 2 - trable linux, 3 - problam with len of path
void output(int n)
{
	switch (n) {
		case 0:
			//
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


char *process(char *path, char *delim)
{
	char *buf_path = malloc(sizeof(char) * slen(path) + 2);//буфер чтоб сток до конца шел
	scpy(buf_path, path);
	buf_path[slen(path)] = *delim;
	buf_path[slen(path) + 1] = '\0';
	char *res = malloc(slen(path));//итоговая строка
	char *tmp;
	for (tmp = stok(buf_path, delim); tmp; tmp = stok(NULL, delim)) {//делим на подстроки весь путь
		if (slen(res)) {//делитель для итоговой строки между подстроками
			scat(res, delim);
		}
		char *buf = malloc(sizeof(char) *slen(tmp) + 2);//буф хранит подстроку
		scpy(buf, tmp);
		buf[slen(buf)] = '\\';//добавление в подстроку слеша чтоб сток шел до конца
		buf[slen(buf) + 1] = 0;
		char *ttmp;
		int a = 0, b = 0; //если есть буква в пути то а = 1, иначе если нет, то б = 1
		if ((ttmp = sstr(buf, ":\\"))) {
			a = 1;
		} else if ((ttmp = sstr(buf, "\\"))){
			b = 1;
		}
		if (a || b) {//windows
			int c = 1;//для прав работы сток
			char *tr = malloc(sizeof(char) * (slen(buf) + 11));//итоговая подстрока
			if (a) {
				scat(tr, "/cygdrive/");
				int n = ttmp - buf;
				c = 3;
				if (n == 1) {//если одна буква в пути
					tr[10] = (char)tolower(buf[0]);
				} else if (n == 2) {//если две буквы в пути
					tr[10] = (char)tolower(buf[0]);
					tr[11] = (char)tolower(buf[1]);
				}
			} else if (b) {//чтоб красиво было
				scat(tr, "/cygdrive");
			}
			char *tmp_t;
			char *tmp_lt = save_static_char();//чтоб сток не сбился
			for (tmp_t = stok(buf + c, "\\"); tmp_t; tmp_t = stok(NULL, "\\")) {//добавление в итоговую подстроку путей исходного путя
				scat(tr, "/");
				scat(tr, tmp_t);
			}
			new_static_char(tmp_lt);//чтоб сток не сбился
			res = realloc(res, slen(res) + slen(tr));//расширяем итоговую строку
			scat(res, tr);
		} else {//linux
			res = realloc(res, slen(res) + slen(tmp));
			scat(res, tmp);//просто добавляем в итоговую строку
		}
	}
	res[slen(res)] = 0;//конец итоговой строки
	return res;
}

int main()
{
	char *path = malloc(sizeof(char) * MAX_PATH);
	char *delim = malloc(sizeof(char) * 1);

	input(path, delim);
	
	int t = check(path, delim);
	if (!t) {
		printf("%s\n", process(path, delim));
	} else {
		output(t);
	}

	return 0;
}
