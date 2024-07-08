#include "func.h"
#include "moveArray.h"
#include <iostream>
using namespace std;

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

int main() {

  testMoveArray();

  return 0;
}