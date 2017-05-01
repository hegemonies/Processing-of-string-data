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

char *_stok(char *s, const char *delim, char **last)
{
	char *spanp, *tok;
	int c, sc;

	if (s == NULL && (s = *last) == NULL)
		return (NULL);
cont:
	c = *s++;
	for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
		if (c == sc)
			goto cont;
	}

	if (c == 0) {
		*last = NULL;
		return (NULL);
	}
	tok = s - 1;
	for (;;) {
		c = *s++;
		spanp = (char *)delim;
		do {
			if ((sc = *spanp++) == c) {
				if (c == 0)
					s = NULL;
				else
					s[-1] = '\0';
				*last = s;
				return (tok);
			}
		} while (sc != 0);
	}
}

char *stok(char *str, const char *delim)
{
	char *last;
	return (_stok(str, delim, &last));
}

/*
int sspn(const char *str, const char *substr);

int scmp(const char *mstr, const char *cpstr);

char *scpy(const char *des, const char *src);
*/