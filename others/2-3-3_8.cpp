#include "../func.h"

/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-19
 * @brief 查找有序数组中元素x
 * 1.如果存在，将其与后继元素交换位置(如果没有后继元素则不交换)
 * 2.如果不存在，将其插入原数组，保持数组仍然有序
 */

void findx(int a[], int size, int x) {
  print(a, size);
  int result = binarySearch(a, size, x);
  if (result < 0) {
    int ins = -(result + 1);

    for (int i = size - 1; i >= ins; i--) {
      a[i + 1] = a[i];
    }
    a[ins] = x;
    cout << "x不存在，插入" << endl;
  } else {
    cout << "元素存在，与后继元素交换位置" << result << endl;
    if (result + 1 <= size - 1) {
      int temp = a[result];
      a[result] = a[result + 1];
      a[result + 1] = temp;
    } else {
      cout << "后继元素不存在!" << endl;
    }
  }
  print(a, size);
}

int main() {

  int a[] = {0, 1, 2, 3, 4, 5, 7, 8, 9, 10};
  int size = sizeof(a) / sizeof(int);
  findx(a, size, 6);
  findx(a, size, 6);

  return 0;
}
