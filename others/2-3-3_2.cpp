/**
 * @brief 逆置数组 [1->2->3] => [3->2->1]
 * @author clb (1265501579@qq.com)
 * @date 2024-07-19
 * @paragraph
 * 思路：双指针从头部和尾部同时向中间遍历，同时交换双指针对应的值
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
#include "../func.h"
void reverseArray(int a[], int size) {
  int low = 0, high = size - 1;
  while (low < high) {
    int temp = a[low];
    a[low] = a[high];
    a[high] = temp;
    low++;
    high--;
  }
}

int main(int argc, char const *argv[]) {

  int a[] = {1, 2, 3, 4, 5};
  int size = sizeof(a) / sizeof(a[0]);
  print(a, size);
  reverseArray(a, size);
  print(a, size);

  return 0;
}
