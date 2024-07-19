/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-19
 * @brief 合并两个有序数组为一个新的有序数组
 */
#include "../func.h"
int *merge(int a[], int l1, int b[], int l2, int c[]) {
  int i = 0, j = 0, k = 0;
  // 合并数组
  while (i < l1 && j < l2) {
    if (a[i] < b[j]) {
      c[k++] = a[i++];
    } else {
      c[k++] = b[j++];
    }
  }
  // 将剩余部分拼接
  if (i == l1) { // a合并完了，将b直接拼接到c
    while (j < l2)
      c[k++] = b[j++];
  } else { // b合并完了，将a直接拼接到c
    while (i < l1)
      c[k++] = a[i++];
  }

  return c;
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 3, 6, 7, 8, 9};
  int l1 = sizeof(a) / sizeof(int);
  int b[] = {0, 2, 4};
  int l2 = sizeof(b) / sizeof(int);
  int c[l1 + l2];

  merge(a, 6, b, 3, c);

  print(a, l1);
  print(b, l2);
  print(c, l1 + l2);

  return 0;
}
