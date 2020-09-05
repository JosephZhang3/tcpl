//
// Created by mac on 2020/9/5.
//
#include "stdio.h"
#include "stdlib.h"

#define MAX_OP 100 // 操作数的最大长度
#define NUMBER '0'

int get_operand(char[]);

void push(double);

double pop(void);

int main() {
    int type;
    double op2;
    char s[MAX_OP]; // 先开一个最大长度的数组，还是Java的可扩容集合好呀

    while ((type = get_operand(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-' :
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero as dividend\n");
                }
                break;
            case '\n':
                // %g 用来输出实数，它根据数值的大小，自动选f格式或e格式（选择输出时占宽度较小的一种），且不输出无意义的0。
                // 即%g是根据结果自动选择科学记数法还是一般的小数记数法
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: invalid expression %s\n", s);
        }
    }

    return 0;
}

// 判断类型的函数库
#include "ctype.h"

int getch(void);

void ungetch(int);

/**
 * 实现从输入中获取操作数
 * @param s
 * @return
 */
int get_operand(char s[]) {
    int i, c;
    // 跳过空格和制表符
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    // 不是数字也不是小数点，直接返回
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    // 是数字 这是整数部分 暂存到s
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }

    // 是小数点 把之后的数字当做小数部分
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }

    // 读取到的不是文件结束符，压回到共享缓冲区中
    if (c != EOF) {
        ungetch(c);
    }

    // debug才能看明白为什么这么写
    // 删除数组末尾的不是 数字、小数点、EOF 的一个字符
    s[i] = '\0';

    return NUMBER; // 标识有用数字都已经被收集起来了
}

#define MAX_DEPTH 100
int sp = 0;
double my_stack[MAX_DEPTH];

/**
 * 把数值压入栈
 * @param n 数值
 */
void push(double n) {
    if (sp < MAX_DEPTH) {
        // 设定数组元素值时让索引变量自增，这是一个有用的 trick
        my_stack[sp++] = n;
    } else {
        printf("error: stack full, can not push %g\n", n);
    }
}

/**
 * 从栈顶弹出数值
 * @return 数值
 */
double pop() {
    if (sp > 0) {
        // 自己第一遍写错的时候写成了 sp-- ，书上说是先自减即 --sp ，why why why
        // 因为sp指向的是栈顶元素的上一个元素，要拿到栈顶元素，就要sp先减一再作为表达式的值
        return my_stack[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#define BUF_SIZE 5

char buf[BUF_SIZE];
int bufp = 0;

/**
 * 取一个字符，可能是存在缓冲区中被压回的字符，也可能是输入流中的字符
 * @return
 */
int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/**
 * 反取，把字符压回到输入流中
 * @param c
 */
void ungetch(int c) {
    if (bufp >= BUF_SIZE) {
        printf("ungetch: too many chars\n");
    } else {
        buf[bufp++] = c;
    }
}
