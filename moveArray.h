/**
 * @brief 将数组左移p个位置
 * 算法思想：创建一个长度和数组R等长的辅助数组，从位置p开始将R数组中元素复制到辅助数组
 * 循环遍历数组R，直到辅助数组被填满，最后将辅助数组中的元素复制给数组R
 *
 * 时间复杂度：while和for循环都为O(n),总的时间复杂度为 O(n)
 * 空间复杂度：借助了一个辅助数组合和一个局部变量，总的空间复杂度为 O(n)
 * @param array 数组R
 * @param len 数组长度
 * @param p 位移长度
 */
void leftShiftArray(int array[], int len, int p) {
  int a[len]; // 辅助数组
  int i = 0;
  while (i < len) {
    a[i] = array[(i + p) % len]; // 循环遍历R
    i++;
  }
  for (int i = 0; i < len; i++) {
    array[i] = a[i];
  }
}
