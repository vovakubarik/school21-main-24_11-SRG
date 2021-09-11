// Copyright 2021 gsherley
#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

int s21_strlen(const char* str) {
    int l = 0;
    while (str[l] != '\0') {
        l++;
    }
    return l;
}

int s21_strcmp(const char* str1, const char* str2) {
    int result = 0, i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && result == 0) {
        if ((int)str1[i] > (int)str2[i]) {
            result = 1;
        }
        if ((int)str1[i] < (int)str2[i]) {
            result = -1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        result = 0;
    } else if (str1[i] == '\0' && str2[i] != '\0') {
        result = -1;
    } else if (str1[i] != '\0' && str2[i] == '\0') {
        result = 1;
    }
    return result;
}

void s21_strcpy(char *destination, const char *source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void s21_strcat(char *destination, const char *append) {
    int i = 0;
    int l = s21_strlen(destination);
    while (append[i] != '\0') {
        destination[l + i] = append[i];
        i++;
    }
    destination[l + i] = '\0';
}

char *s21_strchr(const char *str, int ch) {
    while (*str != (char)ch) {
        if (!*str++) {
            return NULL;
        }
    }
    return (char*)str;
}

char *s21_strstr(const char *strB, const char *strA) {
    int i = 0, len;
    const char* point = NULL, *buf = NULL;
    len = s21_strlen(strB);
    while (strB[i] != '\0') {
        int f = 1;
        int j = 0;
        while (strA[j] != '\0') {
            if (i + j >= len) break;
            if (strB[i+j] == strA[j] && f == 1) {
                buf = strB + i + j;
                f = 2;
            } else if (f != 2){
                f = 0;
            }
        j++;
        }
        if (f == 2) {
            point = buf;
            break;
        }
        i++;
    }
    return (char*)point;
}

char *s21_strtok(char *str, char *sep) {
    static char * last = 0;
    if (str) last = str;
    if ((last == 0) || (*last == 0)) return 0;
    char * c = last;
    while (s21_strchr(sep, *c)) ++c;
    if (*c == 0) return 0;
    char * start = c;
    while (*c && (s21_strchr(sep , *c) == 0)) ++c;
    if (*c == 0) {
        last = c;
        return start;
    }
    *c = 0;
    last = c+1;
    return start;
}
