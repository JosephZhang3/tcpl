//
// Created by zjh on 19-4-5.
//
#include <stdio.h>
#include "exercise1-12.h"

#define IN 1
#define OUT 0

//以每行一个单词的形式打印所有的输入流中的字符
void printout112() {

    int state = OUT, c;
    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n' || c == '\t') {//遇到空格、制表符或者换行符，都表示结束一个单词的输入。可以理解成单词分隔符。
            if (state == IN) {//在IN的状态下输入空格或制表或换行，才标志结束输入一个单词，如果遇到连续的两个空格等，只换一次行，因为只有第一个空格标志单词结束，第二个空格没有任何意义
                putchar('\n');
                state = OUT;
            }
            //else{} 在OUT的状态下输入空格或制表或换行，没有任何作用

        } else if (state == OUT) {//如果输入的不是空格、制表、换行，表示遇到了新单词的第一个字符。（这个地方如果输入其它非单词字母符号就炸了，但不深究了）
            putchar(c);
            state = IN;
        } else {//遇到一个单词中除第一个字符外的其它字符
            putchar(c);
        }
    }
}