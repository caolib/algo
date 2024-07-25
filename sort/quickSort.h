#pragma once
#include "./utils.h"
/**
 * @brief 快速排序
 *
 * 快速排序是一种常用的排序算法，基本思想是通过一趟排序将待排序的记录分割成独立的两部分，
 * 其中一部分记录的关键字均比另一部分记录的关键字小，然后分别对这两部分记录继续进行排序，
 * 以达到整个序列有序的目的。
 *
 * 时间复杂度：
 *   - 平均情况下：O(nlogn)
 *   - 最坏情况下：O(n^2)
 *
 * 空间复杂度：
 *   - 平均情况下：O(logn)
 *   - 最坏情况下：O(n)
 *
 * @param a 待排序的数组
 * @param low 数组的起始下标
 * @param high 数组的结束下标
 */
void quickSort(int a[], int low, int high) {
  if (low >= high)
    return;
  int i = low, j = high;
  while (i < j) {
    while (i < j && a[j] >= a[low]) // 选取第一个数作为基准点，先从右往左扫描
      j--;
    while (i < j && a[i] <= a[low])
      i++;
    swap(a[i], a[j]);
  }
  swap(a[low], a[i]);
  quickSort(a, low, i - 1);
  quickSort(a, i + 1, high);
}