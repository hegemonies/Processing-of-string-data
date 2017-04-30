#ifndef STRINGS_H
#define STRINGS_H

size_t slen(const char *str);

char *stok(const char *str, const char *delim);

int sspn(const char *str, const char *substr);

int scmp(const char *mstr, const char *cpstr);

char *scpy(const char *des, const char *src);

#endif