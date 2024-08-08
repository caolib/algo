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

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void quickSort(int a[], int low, int high) {
  if (low >= high)
    return; // 元素个数小于等于1时返回
  int i = low, j = high;
  int pivot = a[low]; // 选取第一个数作为基准点
  while (i < j) {
    while (i < j && a[j] >= pivot) // 先从右往左扫描,找到第一个小于基准点的数
      j--;
    while (i < j && a[i] <= pivot) // 再从左往右扫描,找到第一个大于基准点的数
      i++;
    swap(a[i], a[j]); // 交换左右指针所指元素
  }
  swap(a[low], a[i]); // 将基准点放到ij相遇的位置
  quickSort(a, low, i - 1);
  quickSort(a, i + 1, high);
}