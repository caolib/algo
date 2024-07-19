/**
 * @brief 删除数组中最小元素(假设唯一)并用最后的元素填补，返回被删除的元素
 * [1,2,3,4,-2,8,6] => [1,2,3,4,6,8]
 * @author clb (1265501579@qq.com)
 * @date 2024-07-19
 */
#include "../func.h"
int deleteMin(int a[], int size) {
  int index = 0;
  for (int i = 1; i < size; i++) {
    if (a[i] < a[index]) {
      index = i;
    }
  }
  int min = a[index];
  a[index] = a[size - 1];
  a[size - 1] = INT_MAX;
  return min;
}

int main(int argc, char const *argv[]) {

  int a[] = {1, 2, 3, 4, -2, 8, 6};
  int size = sizeof(a) / sizeof(a[0]);
  print(a, size);
  deleteMin(a, size);
  print(a, size - 1);

  return 0;
}
