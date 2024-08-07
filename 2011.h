#pragma once
#include "func.h"
/**
 * @brief [2011 统考真题]找出两个升序数组的中位数(包含两个数组所有元素的中位数)
 * 中位数为:第<数组长度/2(向上取整)> 个元素
 * @author clb (1265501579@qq.com)
 * @date 2024-07-13
 * @paragraph
 * 算法思想：将两个数组合并为一个升序数组，然后找出中位数即可(归并排序一次归并)
 * 时间复杂度：O(n),只有单层while循环
 * 空间复杂度：O(n),使用了一个辅助数组，长度为两个数组长度之和
 */
int midNumber(int a[], int l1, int b[], int l2) {
  int len = l1 + l2;
  int target[len]; // 合并后的数组

  // 合并数组
  int i = 0, j = 0, k = 0;
  while (i < l1 && j < l2) {
    if (a[i] < b[j])
      target[k++] = a[i++];
    else
      target[k++] = b[j++];
  }
  // 将数组剩余元素全部复制到目标数组
  while (i < l1)
    target[k++] = a[i++];
  while (j < l2)
    target[k++] = b[j++];

  print(target, len);
  return target[len / 2];
}