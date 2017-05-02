#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include <stdint.h>
#include <sys/types.h>

size_t slen(const char *str)
{
	if (str[0] == '\0' || str[0] == '\n') {
		return 0;
	}
	int count;
	for (int i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return count;
}
/*
char *_stok(char *s, const char *delim, char **last)
{

}
*/
//static char *lt = NULL;

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

/*
int sspn(const char *str, const char *substr);

int scmp(const char *mstr, const char *cpstr);

char *scpy(const char *des, const char *src);
*/
