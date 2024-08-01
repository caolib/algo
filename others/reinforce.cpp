/**
 * @author libin (1265501579@qq.com)
 * @date 2024-08-01
 */

/**
 * @brief
 * 找到一个升序数组中出现次数大于2的元素(假设只有一个)，返回该元素出现的次数
 */

int countK(int a[], int size) {
  int i = 0, j = 1; // 前后指针
  while (j < size) {
    if (a[i] == a[j]) // 已经找到k了
      break;
    i++;
    j++;
  }
  int k = a[i]; // k
  k++;          // 后指针后移一位
  int count = 2; // k出现的次数,从后指针下一个位置开始统计，所以初始是2
  while (j < size) {
    if (a[j] != k)
      break;
    count++;
    j++;
  }
  return count;
}

#include <iostream>

void testCountK() {
  int arr[] = {1, 2, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int result = countK(arr, size);
  std::cout << "The element occurs " << result << " times." << std::endl;
}

int main() {
  testCountK();
  return 0;
}