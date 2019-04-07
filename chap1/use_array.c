//
// Created by zjh on 19-4-7.
//

#include <stdio.h>
#include "use_array.h"


void stat_char_count() {
    //在c语言中，每个字符都有其整形表示

    //the count of white space and other characters
    int c, i, nwhite, nother;
    nwhite = nother = 0;

    int ndigit[10];//the count of number from 1 to 9
    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {//判断变量c中的字符是否是数字
            ++ndigit[c - '0'];
            //表达式充当数组的合法下标，基于下面的事实
            // '0' - '0' = 0
            // '1' - '0' = 1
            // '2' - '0' = 2
            // ...
            // '9' - '0' = 9
        } else if (c == ' ' || c == '\t' || c == '\n') {
            ++nwhite;
        } else {
            ++nother;
        }
    }

    printf("数字个数\n");
    for (i = 0; i < 10; i++) {
        printf("%d\t%d\n", i, ndigit[i]);
    }

    printf("空白字符个数%d,其它字符个数%d\n", nwhite, nother);
}