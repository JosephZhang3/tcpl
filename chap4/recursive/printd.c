#include "stdio.h"

void print_d(int);

int main() {
    print_d(123);
    return 0;
}

/**
 * 将一个数作为字符串打印
 * @param n
 */
void print_d(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }

    // 递归终止条件：n/10 == 0
    if (n / 10) {
        printf("本层调用参数 n = %d, （递）指向更低一层调用 n = %d\n", n, n / 10);
        print_d(n / 10);
    }

    putchar(n % 10 + '0'); // 数字转换为字符
    printf("\n n = %d 层。（归）打印数字 %d 模 10 的结果 %c\n", n, n, n % 10 + '0');
}