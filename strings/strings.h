#ifndef STRINGS_H
#define STRINGS_H

int slen(const char *str);

char *stok(char *str, const char *delim);

int sspn(char *str, const char *substr);

int scmp(const char *mstr, const char *cpstr);

char *scpy(char *des, const char *src);

char *scat(char *des, const char *src);

char *sstr(char *string1, const char *string2);

#endif
