//
// Created by zjh on 19-4-5.
//

#include <stdio.h>
#include "word_count.h"

#define IN 1
#define OUT 2

/*单词计数程序*/
void word_count() {

    //变量定义：当前输入的字符，行计数器，单词计数器，字符计数器，位置状态（在单词内还是在单词外）
    int c, lc, wc, cc, state;
    lc = wc = cc = 0;
    state = OUT;//第一个位置肯定是在单词外

    while ((c = getchar()) != EOF) {
        cc++;
        if (c == '\n') {
            lc++;
        }
        if (c == ' ' || c == '\n' || c == '\t') {//遇到空格、制表符或者换行符，都表示结束一个单词的输入
            state = OUT;
        } else if (state == OUT) {//如果输入的不是空格、制表、换行，表示新开始一个单词的输入。（这个地方如果输入其它非单词字母符号就炸了，但不深究了）
            state = IN;
            wc++;
        }

    }
    printf("%d %d %d\n", lc, wc, cc);

}