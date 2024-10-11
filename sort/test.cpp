/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-25
 */
#include "../func.h"
#include "./insertSort.h"
#include "./qSort.h"
#include "./selectSort.h"
#include "bubbleSort.h"
#include "quickSort.h"
#include "utils.h"
#include <functional>
/**
 * @brief 排序算法测试
 * @param sort 排序函数
 */
void testSortAlgorithm(function<void(int *, int, int)> sort) {
  // int a[] = {1, 1, 1, 1, 1};
  int a[] = {5, 4, 3, 2, 1};
  int size = sizeof(a) / sizeof(a[0]);
  print(a, size);
  sort(a, 0, size - 1);
  print(a, size);
  cout << endl;
}
void testSortAlgorithm(function<void(int *, int)> sort) {
  int a[] = {5, 4, 3, 2, 1};
  int size = sizeof(a) / sizeof(int);
  print(a, size);
  sort(a, size);
  print(a, size);
  cout << endl;
}

int main() {

  testSortAlgorithm(quickSort);    // 快排
  testSortAlgorithm(bubbleSort);   // 冒泡
  testSortAlgorithm(bubbleSortII); // 冒泡II
  testSortAlgorithm(insertSort);   // 插入排序
  testSortAlgorithm(selectSort);   // 选择排序

  return 0;
}
