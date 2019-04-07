#include <stdio.h>

//定义符号常量
#define CINT 9
#define CSTR "achar"

#include "chap1/character_count.h"
#include "chap1/row_count.h"
#include "chap1/exercise1-8.h"
#include "chap1/exercise1-9.h"
#include "chap1/exercise1-10.h"
#include "chap1/word_count.h"
#include "chap1/exercise1-12.h"
#include "chap1/use_array.h"

int main() {
    printf("Hello, World!\n");

    printf("%d\n", CINT);
    printf("%s\n", CSTR);//打印字符常量，注意大写以与普通变量命名区分

    printf("special\y\n");
    printf("special\7\n");
    printf("special\?\n");

    printf("%d\n", 5 / 9);//注意了，整型除法相除并舍位后得到的结果为０　这是ｃ语言的规矩
    printf("%f\n", 5.0 / 9.0);//浮点型除法，相除后结果不会被舍位
    printf("%f\n", 5 / 9.0);//如果算式中有一个浮点型操作数和一个整型操作数，整形操作数会被转换成浮点型

    /*//打印EOF的值是整型值-1
    printf("%d\n", EOF);

    //可是，即使你手动输-1或者敲换行符，依然不等于EOF，因为EOF是文件结束符
    printf("%d\n", getchar() != EOF);

    //把输入复制到输出
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }*/

//    character_count();//字符计数

    //row_count();//行计数

//    count18();
//    count19();

//    replace110();
//    word_count();

//    printout112();

    stat_char_count();
    return 0;
}