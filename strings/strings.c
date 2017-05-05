#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include <stdint.h>
#include <string.h>

int slen(char *str)
{
	int count = 0;;
	for (int i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return count++;
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


int sspn(char *str, const char *substr)
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
	des[i] = 0;
	return des;
}

char *scat(char *des, const char *src)
{
	int j = slen(des);
	for (int i = 0; src[i] != 0; i++) {
		des[j] = src[i];
		j++;
	}
	des[j] = 0;
	return des;
}
/*
char *sstr(char *string1, const char *string2)
{
	char *strptr = string1;
	int j = 0;
	for (int i = 0; string1[i] != 0; i++) {
		if (string2[j] == 0) {
			return strptr;
		}
		if (string1[i] != string2[j]) {
			j = 0;
			continue;
		}
		if (string1[i] == string2[j]) {
			if (j == 0) {
				strptr = string1 + i;
			}
			j++;
		}
	}
	if (string2[j] == 0) {
		return strptr;
	} else {
		return NULL;
	}
}
*/

char *sstr(const char *str1,  const char *str2, int slen){
    unsigned char max_len = 140;
    if ( !*str2 )
        return((char *)str1);
    //Очистка массивов
    unsigned char index_header_first[256];
    unsigned char index_header_end[256];
    unsigned char last_char[256];
    unsigned char sorted_index[256];
    memset(index_header_first,0x00,sizeof(unsigned char)*256);
    memset(index_header_end,0x00,sizeof(unsigned char)*256);
    memset(last_char,0x00,sizeof(unsigned char)*256);
    memset(sorted_index,0x00,sizeof(unsigned char)*256);
    //Этап 1.
    char *cp2 = (char*)str2;
    unsigned char v;
    unsigned int len =0;
    unsigned char current_ind = 1;
    while((v=*cp2) && (len<max_len)){
        if(index_header_first[v] == 0){
            index_header_first[v] = current_ind;
            index_header_end[v] = current_ind;
            sorted_index[current_ind] = len;
        }
        else{
            unsigned char last_ind = index_header_end[v];
            last_char[current_ind] = last_ind;
            index_header_end[v] = current_ind;
            sorted_index[current_ind] = len;
        }
        current_ind++;
        len++;
        cp2++;
    }
    if(len > slen){
        return NULL;
    }
    //Этап 2.
    unsigned char *s1, *s2;
    //Начинаем проверку с элемента S+pl-1
    unsigned char *cp = (unsigned char *) str1+(len-1);
    unsigned char *cp_end= cp+slen;
    while (cp<cp_end){
        unsigned char ind = *cp;
        //Если выбранный элемент есть в строке P
        if( (ind = index_header_end[ind]) ) {
            do{
                //Тогда проверяем все возможные варианты с участием этой буквы
                unsigned char pos_in_len = sorted_index[ind];
                s1 = cp - pos_in_len;
                if((char*)s1>=str1)
                {
                    //Сравниваем строки
                    s2 = (unsigned char*)str2;
                    while ( *s2 && !(*s1^*s2) )
                        s1++, s2++;
                    if (!*s2)
                        return (char*)(cp-pos_in_len);
                }
            }
            while( (ind = last_char[ind]) );
        }
        //Прыгаем вперёд на pl
        cp+=len;
    }
    return(NULL);
}