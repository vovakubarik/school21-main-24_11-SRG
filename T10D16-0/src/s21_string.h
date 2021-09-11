#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

int s21_strlen(const char* str);
void s21_strlen_test();
int s21_strcmp(const char* str1, const char* str2);
void s21_strcmp_test();
void s21_strcpy(char *destination, const char *source);
void s21_strcpy_test();
void s21_strcat(char *destination, const char *append);
void s21_strcat_test();
char *s21_strchr(const char *str, int ch);
void s21_strchr_test();
char *s21_strstr(const char *strB, const char *strA);
void s21_strstr_test();
char *s21_strtok(char *str, char *sep);
void s21_strtok_test();

#endif  // SRC_S21_STRING_H_
