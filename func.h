#pragma once
#include <iostream>

/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-08
 */

using namespace std;
/**
 * @brief 打印数组
 * @param arr 数组
 * @param len 数组长度
 */
void print(int arr[], int len) {
  cout << "[ ";
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << "]" << endl;
}

/**
 * @brief 二分查找
 * @param a 有序数组
 * @param size 数组大小
 * @param e 目标元素
 * @return int 找到 -> 目标元素索引;没找到 -> 目标元素应该插入的位置
 */
int binarySearch(int a[], int size, int e) {
  int left = 0, right = size - 1;
  int mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (a[mid] == e) {
      return mid;
    }
    if (e < a[mid]) {
      right = mid - 1;
    } else if (e > a[mid]) {
      left = mid + 1;
    }
  }
  return -left - 1;
}