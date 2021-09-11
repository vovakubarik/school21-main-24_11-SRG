#include "documentation_module.h"
#include <string.h>
#include <stdarg.h>
#include "math.h"
#include <stdio.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

short check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list factor;
    short binMask = 0;
    int k = 0;
    va_start(factor, document_count);
    while (document_count) {
        char* doc;
        doc = va_arg(factor, char*);
        if (validate(doc) == 1) {
            binMask += pow(2, k);
        }
        k++;
        document_count--;
    }
    va_end(factor);
    return binMask;
}

void output_available_documents(short mask, int document_count, ...) {
    va_list factor;
    int p = 1;
    va_start(factor, document_count);
    while (document_count) {
        char* doc;
        doc = va_arg(factor, char*);
        printf("%d. %-15s : ", p, doc);
        if (mask % 2 != 0) {
            printf("available\n");
        } else {
            printf("unavailable\n");
        }
        document_count--;
        p++;
        mask /= 2;
    }
    va_end(factor);
}
