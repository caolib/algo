/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-25
 */
#include "../func.h"
#include "bubbleSort.h"
#include "quickSort.h"
#include "utils.h"
#include <functional>
/**
 * @brief 排序算法测试
 * @param sort 排序函数
 */
void testSortAlgorithm(int *a, int size, function<void(int *, int, int)> sort) {
  shuffleArray(a, size);
  cout << "排序前：";
  print(a, size);
  sort(a, 0, size - 1);
  cout << "排序后：";
  print(a, size);
  cout << endl;
}
void testSortAlgorithm(int *a, int size, function<void(int *, int)> sort) {
  shuffleArray(a, size);
  cout << "排序前：";
  print(a, size);
  sort(a, size - 1);
  cout << "排序后：";
  print(a, size);
  cout << endl;
}

int main() {

  int a[] = {4, 3, 2, 6, 8, -3, 5};
  int size = sizeof(a) / sizeof(a[0]);

  testSortAlgorithm(a, size, quickSort);  // 快排
  testSortAlgorithm(a, size, bubbleSort); // 冒泡

  return 0;
}
