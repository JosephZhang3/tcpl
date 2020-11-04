//
// Created by mac on 2020/9/12.
//

#include "stdio.h"

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right) {
    if (left >= right) {
        return;
    }

    swap(v, left, (left + right) / 2);
    int last = left;
    for (int i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);

    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

int main() {
    int a[] = {34, 3, 42, 2, 9, 1};
    qsort(a, 0, 5);
    for (int i = 0; i < 6; ++i) {
        printf("%d\t", a[i]);
    }
}