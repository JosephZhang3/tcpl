//
// Created by zjh on 19-4-5.
//
#include <stdio.h>

//字符计数例程，注意只有在终端下才能使用Ctrl+D结束输入，在console下无法对输入的字符进行计数
void character_count() {

    //for循环，不如while循环看得清晰
/*    double cc;
    for (cc = 0; getchar() != EOF; ++cc);
    printf("%.0f\n", cc);*/

    double cc = 0;
    while (getchar() != EOF)
        cc++;
    printf("%.0f\n", cc);

}
