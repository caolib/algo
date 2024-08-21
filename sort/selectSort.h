/**
 * @author libin (1265501579@qq.com)
 * @date 2024-08-21
 * @paragraph
 * 选择排序：每次遍历未排序区间，从中找出最小的元素，将其放到有序区间的最后
 */

#include "./utils.h"

void selectSort(int a[], int size) {
  for (int i = 0; i < size; i++) {
    int index = i; // 最小元素索引
    for (int j = i + 1; j < size; j++) {
      if (a[j] < a[index])
        index = j;
    }
    swap(a[i], a[index]);
  }
}