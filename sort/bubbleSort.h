#pragma once
#include "./utils.h"
#include <iostream> // 添加这个头文件以使用 std::cout

void bubbleSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
    }
  }
}
void bubbleSortII(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    bool change = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        change = true;
      }
    }
    if (!change) // 如果一轮循环一次都没有交换元素，说明数组已经有序
      return;
  }
}