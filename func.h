/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-08
 */
#pragma once
#include <iostream>
using namespace std;
/**
 * @brief 打印数组
 *
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