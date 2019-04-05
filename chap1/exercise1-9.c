//
// Created by zjh on 19-4-5.
//
#include <stdio.h>
#include "exercise1-9.h"

#define NONBLANK 'a'

/**
 把输入复制到输出，把其中连续的多个空格用一个空格替代
 */
void count19() {

//    int isws = 0;//输入的上一个字符是否是空格，０是，１否
//    int c;
//
//    while ((c = getchar()) != EOF) {
//        if (c == ' ') {
//            //输入的上一个字符不是空格，且输入的当前字符是空格，才打印当前空格，并且置标志位
//            if (isws == 0) {
//                putchar(c);
//                isws = 1;
//            }
//            //输入的上一个字符和当前字符都是空格，不打印当前空格
//        } else {
//            //输入的当前字符不是空格，打印并且重置标志位
//            putchar(c);
//            isws = 0;
//        }
//    }


//下面来一个漂亮的实现
    int c, lastc;
    lastc = NONBLANK;//符号常量，这里用于初始化变量的值
    while ((c = getchar()) != EOF) {
        //只有两种情况才把字符复制到输出，1：当前输入的字符不是空格，2：上一个输入的字符不是空格
        if (c != ' ' || lastc != ' ') {
            putchar(c);
        }
        lastc = c;//记录上一个输入的字符
    }
}