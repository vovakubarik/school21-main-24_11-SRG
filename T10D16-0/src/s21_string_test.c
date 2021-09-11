#include <stdio.h>
#include "s21_string.h"

void s21_strlen_test() {
    printf("Tests for s21_strlen: \n");
    int len = 0;
    printf("Strings\n");
    len = s21_strlen("Strings");
    printf("%d\n", len);
    len == 7 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("Life is strange\n");
    len = s21_strlen("Life is strange");
    printf("%d\n", len);
    len == 13 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("\n");
    len = s21_strlen("");
    printf("%d\n", len);
    len == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcmp_test() {
    printf("Tests for s21_strcmp: \n");
    int status;
    printf("Strings Strings\n");
    status = s21_strcmp("Strings", "Strings");
    printf("%d\n", status);
    status == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("  Campus\n");
    status = s21_strcmp("", "Campus");
    printf("%d\n", status);
    status > 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("DOG @\n");
    status = s21_strcmp("DOG", "@");
    printf("%d\n", status);
    status > 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcpy_test() {
    printf("Tests for s21_strcpy: \n");
    char str1[] = "17Strings";
    char str2[] = "CAT";
    char str3[] = "17floor\0S";
    printf("%s %s\n", str1, str2);
    s21_strcpy(str1, str2);
    printf("%s %s\n", str1, str2);
    s21_strcmp(str1, str2) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("%s %s\n", str3, str1);
    s21_strcpy(str3, str1);
    printf("%s %s\n", str3, str1);
    s21_strcmp(str3, str1) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    printf("%s %s\n", str2, str3);
    s21_strcpy(str2, str3);
    printf("%s %s\n", str2, str3);
    s21_strcmp(str2, str3) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcat_test() {
    printf("Tests for s21_strcat: \n");
    char str1[] = "17Strings";
    char str2[] = "CAT";
    char str3[] = "17floor\0S";
    char str4[50];
    s21_strcpy(str4, str1);
    printf("%s %s\n", str1, str2);
    s21_strcat(str4, str2);
    printf("%s\n", str4);
    s21_strcmp(str4, "17StringsCAT") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    printf("%s %s\n", str4, str1);
    s21_strcat(str4, str1);
    printf("%s\n", str4);
    s21_strcmp(str4, "17StringsCAT17Strings") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");

    printf("%s %s\n", str4, str3);
    s21_strcat(str4, str3);
    printf("%s\n", str4);
    s21_strcmp(str4, "17StringsCAT17Strings17floor") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strchr_test() {
    printf("Tests for s21_strchr: \n");
    char str1[] = "17Strings";
    char str2[] = "CAT";
    char str3[] = "floor17\0S";
    char t = '7', *result;
    printf("%s %c\n", str1, t);
    if (s21_strchr(str1, t) != NULL) {
        result = s21_strchr(str1, t);
        printf("%d\n", (int)(result-str1));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("%s %c\n", str2, t);
    if (s21_strchr(str2, t) != NULL) {
        result = s21_strchr(str2, t);
        printf("%d\n", (int)(result-str2));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("%s %c\n", str3, t);
    if (s21_strchr(str3, t) != NULL) {
        result = s21_strchr(str3, t);
        printf("%d\n", (int)(result-str3));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
}

void s21_strstr_test() {
    printf("Tests for s21_strstr: \n");
    char str1[] = "175Strings";
    char str2[] = "CAT";
    char str3[] = "Sfloor175s";
    char *result;
    printf("%s %s\n", str1, str2);
    if (s21_strstr(str1, str2) != NULL) {
        result = s21_strstr(str1, str2);
        printf("%d\n", (int)(result-str1));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("%s %s\n", str3, str1);
    if (s21_strstr(str3, str1) != NULL) {
        result = s21_strstr(str3, str1);
        printf("%d\n", (int)(result-str3));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
    printf("%s %s\n", str1, str3);
    if (s21_strstr(str1, str3) != NULL) {
        result = s21_strstr(str1, str3);
        printf("%d\n", (int)(result-str1));
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
}

void s21_strtok_test() {
    printf("Tests for s21_strtok: \n");
    char str1[] = "We will swim to the end, be sure";
    char str2[] = ",";
    printf("%s %s\n", str1, str2);
    char *result = s21_strtok(str1, str2);
    if (result != NULL) {
        while (result != NULL) {
            printf("%s\n", result);
            result = s21_strtok(NULL, str2);
        }
        printf("SUCCESS\n");
    } else {
        printf("NULL\n");
        printf("FAIL\n");
    }
}
