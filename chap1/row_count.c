//
// Created by zjh on 19-4-5.
//

#include <stdio.h>
#include "row_count.h"

//行计数，注意，这个函数要在terminal中执行，不能在console中执行，否则不会打印
void row_count() {
    int c, nc = 0;//变量C接收一个字符或者EOF，变量nc表示行数

    while ((c = getchar()) != EOF) {
        //行数等价于换行符个数
        if (c == '\n') {
            nc++;
        }
    }

    printf("%d\n", nc);
}