//
// Created by zjh on 19-4-5.
//

#include "exercise1-8.h"
#include <stdio.h>

void count18() {

    //空格符，制表符，换行符
    //white space count,tabulate count,next line count
    int wscount = 0, tabcount = 0, nlcount = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            wscount++;
        else if (c == '\t')
            tabcount++;
        else if (c == '\n')
            nlcount++;
        else;
    }

    printf("空格符个数%d\n", wscount);
    printf("制表符个数%d\n", tabcount);
    printf("换行符个数%d\n", nlcount);
}