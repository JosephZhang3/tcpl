//
// Created by zjh on 19-4-5.
//
#include <stdio.h>
#include "exercise1-10.h"

void replace110() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
}