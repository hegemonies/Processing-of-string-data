#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include <stdint.h>

size_t slen(const char *str)
{
	if (str[0] == '\0') {
		return 0;
	}
	int count;
	for (int i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return count;
}

char *stok(char *str, const char *delim)
{
	static char *lt;
	if (str != NULL) {
		lt = str;
	}
	for (int i = 0; lt[i] != 0; i++) {
		for (int j = 0; delim[j] != 0; j++) {
			if (lt[i] == delim[j]) {
				lt[i] = 0;
				str = lt;
				lt = lt + i + 1;
				return str;
			}
		}
	}
	return str;
}


int sspn(const char *str, const char *substr)
{
	int count = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == substr[i]) {
			count++;
		} else {
			return count;
		}
	}
	return 0;
}

int scmp(const char *str, const char *strc)
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

char *scpy(char *des, const char *src)
{
	int i;
	for (i = 0; src[i] != 0; i++) {
		des[i] = src[i];
	}
	des[i + 1] = '\0';
	return des;
}