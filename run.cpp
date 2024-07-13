/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-08
 */
#include "2010.h"
#include "2011.h"
#include "func.h"
#include <iostream>
using namespace std;

/**
 * @brief 测试数组左移
 */
void testMoveArray() {
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(array) / sizeof(int);
  // 左移1位
  leftShiftArray(array, size, 1);
  print(array, size);
  // 左移2位
  leftShiftArray(array, size, 2);
  print(array, size);
  // 左移3位
  leftShiftArray(array, size, 3);
  print(array, size);
}

/**
 * @brief 测试寻找两个数组的中位数
 */
void testMidNumber() {
  // int a[] = {11, 13, 15, 17, 19};
  int a[] = {1, 2, 5};
  int l1 = sizeof(a) / sizeof(int);
  // int b[] = {2, 4, 6, 8, 20};
  int b[] = {0, 7, 8};
  int l2 = sizeof(b) / sizeof(int);

  cout << midNumber(a, l1, b, l2) << endl;
}
int main() {

  // testMoveArray();

  testMidNumber();

  return 0;
}