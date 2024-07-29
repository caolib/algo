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
    if (a[i] < b[j]) {
      target[k] = a[i];
      i++;
    } else {
      target[k] = b[j];
      j++;
    }
    k++;
  }
  // 哪个数组还有剩余，将其全部复制到目标数组
  if (i <= l1 - 1) {
    while (i < l1) {
      target[k++] = a[i++];
    }
  } else {
    while (j < l2) {
      target[k++] = b[j++];
    }
  }

  print(target, len);
  int index;
  if (len % 2 == 0)
    index = len / 2 - 1;
  index = len / 2;
  // 返回中位数
  return target[index];
}

/**
 * @brief 两个数组升序，使用双指针一边比较一边移动
 */
// FIXME 结果和正确结果相差一个位置
int midNumberII(int a[], int l1, int b[], int l2) {
  int i = 0, j = 0;
  int count = (l1 + l2) / 2;
  int min1 = 0, min2 = 0;
  bool isEven = (l1 + l2) % 2 == 0;

  while (i < l1 && j < l2 && count >= 0) {
    if (a[i] < b[j]) {
      min2 = min1;
      min1 = a[i];
      i++;
    } else {
      min2 = min1;
      min1 = b[j];
      j++;
    }
    count--;
  }

  while (count >= 0 && i < l1) {
    min2 = min1;
    min1 = a[i];
    i++;
    count--;
  }

  while (count >= 0 && j < l2) {
    min2 = min1;
    min1 = b[j];
    j++;
    count--;
  }

  if (isEven) {
    return (min1 + min2) / 2;
  } else {
    return min1;
  }
}