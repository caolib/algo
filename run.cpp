/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-08
 */
#include "2010.h"
#include "2011.h"
#include "2013.h"
#include "2018.h"
#include "func.h"
#include <functional>
#include <iostream>
using namespace std;

/**
 * @brief 测试数组左移
 */
void runMoveArray(int array[], int size, int p,
                  function<void(int *, int, int)> shift) {
  shift(array, size, p);
  print(array, size);
}
void testMoveArray() {
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(array) / sizeof(int);
  // 左移1/2/3位
  runMoveArray(array, size, 1, leftShiftArray);
  runMoveArray(array, size, 2, leftShiftArray);
  runMoveArray(array, size, 3, leftShiftArray);
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

/**
 * @brief 测试寻找主元素
 */
void runMainElement(int a[], int len, function<int(int *, int)> func,
                    string s) {
  int result = func(a, len);
  cout << (result == -1 ? "不存在主元素！" : "主元素为" + to_string(result))
       << "\t\t[" << s << "]" << endl;
}

void testMainElement() {
  // 数组模拟哈希表解法
  int a[] = {0, 5, 5, 3, 5, 7, 5, 5};
  int l1 = sizeof(a) / sizeof(int);
  int b[] = {0, 5, 5, 3, 5, 1, 5, 7};
  int l2 = sizeof(b) / sizeof(int);
  string s = "数组模拟哈希表解法";
  runMainElement(a, l1, mainElementI, s);
  runMainElement(b, l2, mainElementI, s);

  // 哈希表解法
  s = "哈希表解法";
  runMainElement(a, l1, mainElementII, s);
  runMainElement(b, l2, mainElementII, s);
  // 暴力解法
  s = "暴力解法";
  runMainElement(a, l1, mainElementIII, s);
  runMainElement(b, l2, mainElementIII, s);
}

// 2018
void runFindNotExist(int array[], int len, function<int(int *, int)> function,
                     string s) {
  cout << "不存在最小正整数为：" << function(array, len) << "\t\t[" << s << "]"
       << endl;
}

void testFindNotExist() {
  int a[] = {-5000, 3, 1, 3};
  int l1 = sizeof(a) / sizeof(int);
  int b[] = {1, 2, 3};
  int l2 = sizeof(b) / sizeof(int);
  string s = "暴力解法";
  runFindNotExist(a, l1, findNotExistII, s);
  runFindNotExist(b, l2, findNotExistII, s);

  s = "数组解法";
  runFindNotExist(a, l1, findNotExist, s);
  runFindNotExist(b, l2, findNotExist, s);
}

int main() {

  // testMoveArray();

  // testMidNumber();

  // testMainElement();

  testFindNotExist();

  return 0;
}