#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_file(char* name);
int writein_file(char* name, char* str);

int main() {
    int menu, f, f1 = 0, n = 100;
    char *name_file;
    char c;
    char *name_buf = malloc(n*sizeof(char));
    char *writeStr = malloc(n*sizeof(char));
    int key = 1;
    while (key) {
    scanf("%d", &menu);
    switch (menu) {
        case 1:
        name_file = malloc(n*sizeof(char));
        f = 0;
            for (int i = 0; i < n; i++) {
                c = getc(stdin);
                if (c == '\n') break;
                f = 1;
                name_file[i] = c;
            }
            if (f) {
                f1 = 1;
                name_buf = name_file;
                f = read_file(name_buf);
                if (f == 0) {
                printf("n/a");
                printf("\n");
                free(name_file);
            }
        }
        break;

        case 2:
        while ((c = getchar()) != '\n' && c != EOF) {}
                fgets(writeStr, 100, stdin);
            if (f1) {
                f = writein_file(name_file, writeStr);
                if (f == 0) {
                printf("n/a");
                printf("\n");
            }
            } else {
                printf("n/a");
                printf("\n");
            }
        break;

        case -1:
        key = 0;
        break;

        default:
        printf("n/a");
        key = 0;
        break;
    }
}

free(writeStr);
free(name_buf);
free(name_file);
    return 0;
}

int read_file(char* name) {
    FILE* fp;
    int f = 1;
    char nameF[100]= "../src/";
    strncat(nameF, name, strlen(name) + 7);
    fp = fopen(nameF, "r");
    if (fp == NULL) f = 0;
    if (f) {
        fseek(fp, 0L, SEEK_END);
        int sz = ftell(fp);
        fclose(fp);
        if (sz) {
            fp = fopen(nameF, "r");
        char* str = malloc(100*sizeof(char));
        while (!feof(fp)) {
            if (fgets(str, 100, fp))
            printf("%s", str);
        }
        fclose(fp);
        printf("\n");
        if (str) free(str);
        } else {
            f = 0;
        }
    }
    return f;
}

int writein_file(char* name, char* str) {
    FILE* fp;
    int f = 1;
    char nameF[100]= "../src/";
    strncat(nameF, name, strlen(name) + 7);
    if ((fp = fopen(nameF, "r")) == NULL) {
        f = 0;
    }
    if (f) {
        fseek(fp, 0L, SEEK_END);
        int sz = ftell(fp);
        fclose(fp);
        if (sz) {
            fp = fopen(nameF, "a");
            fprintf(fp, "%s", str);
            fclose(fp);
            read_file(name);
        } else {
            fp = fopen(nameF, "a");
            fprintf(fp, "%s", str);
            fclose(fp);
            read_file(name);
        }
    }
    return f;
}
