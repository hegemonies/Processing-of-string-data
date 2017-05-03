#ifndef STRINGS_H
#define STRINGS_H

int slen(const char *str);

char *stok(char *str, const char *delim);

int sspn(const char *str, const char *substr);

int scmp(const char *mstr, const char *cpstr);

char *scpy(char *des, const char *src);

#endif
