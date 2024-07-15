#pragma once
/**
 * @brief [2018 统考真题] 找出一个数组中未出现的最小整数
 * @author clb (1265501579@qq.com)
 * @date 2024-07-15
 * @paragraph
 * 算法思想：如果给定数组长度为len，那么未出现的最小整数最大为len+1(例：数组长度为3，元素为{1,2,3},
 * 此时未出现的最小正整数最大为4)，因此可以使用1个长度为len+2的bool数组统计各个正整数出现的情况然后
 * 从小到大遍历该数组就能确定未出现的最小正整数
 * 时间复杂度：O(n)，2个单层for循环
 * 空间复杂度：O(n)，使用了1个长度为len+2的exist数组
 */
int findNotExist(int array[], int len) {
  bool exist[len + 2]; // 索引为0~len+1,可以包含所有情况
  // 统计数组元素出现情况
  for (int i = 0; i < len; i++)
    // 只统计1~len+1范围内的数
    if (array[i] >= 1 && array[i] <= len + 1)
      exist[array[i]] = true;

  // 遍历数组(1~len+1,0不是正整数)找出未出现的最小正整数
  for (int i = 1; i < len + 2; i++)
    if (!exist[i])
      return i;

  return -1;
}

/**
 * @brief 暴力解法
 * @paragraph
 * 算法思想：从1开始将正整数一个一个到数组中查找，直到找到第一个不存在于数组中的正整数
 * 时间复杂度：O(n^2),while循环中使用了find函数，find为O(n)级别，总体为O(n^2)级别
 * 空间复杂度：O(1)，只使用了1个局部变量
 */

// 查找一个元素是否存在于数组中
bool find(int array[], int len, int e) {
  for (int i = 0; i < len; i++)
    if (array[i] == e)
      return true;
  return false;
}

int findNotExistII(int array[], int len) {
  int e = 1;
  while (true) {
    if (!find(array, len, e)) {
      return e;
    }
    e++;
  }
}
