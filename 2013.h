#pragma once
#include <unordered_map>
using namespace std;
/**
 * @brief [2013 统考真题]
 * 如果一个数组(数组元素和个数范围都是[0,n)，n为数组长度)中某个元素出现次数 >
 * 数组长度的一半,则该元素是数组的主元素。设计算法找出一个数组的主元素，如果没有返回-1
 * @author clb (1265501579@qq.com)
 * @date 2024-07-14
 * @brief 数组模拟哈希表(因为题目给的元素有范围而且比较小)
 * 算法思想：map数组索引作为数组元素，索引对应的值为次数
 * 时间复杂度：O(n),3个单层for循环
 * 空间复杂度：O(n)，使用了1个长度为len的数组
 */
int mainElementI(int array[], int len) {
  // 初始化映射数组
  int map[len];
  for (int i = 0; i < len; i++)
    map[i] = 0;

  // 统计出现次数
  for (int i = 0; i < len; i++) {
    map[array[i]]++;
  }

  // 遍历数组，查找主元素
  for (int i = 0; i < len; i++) {
    if (map[i] > len / 2) {
      return i;
    }
  }
  return -1;
}

/**
 * @brief 哈希表解法(408可能不允许使用STL模板库)
 * @paragraph
 * 算法思想：使用哈希表统计数组中每个数出现的次数，遍历哈希表找出主元素
 * 时间复杂度：O(n),2个单层for循环;unordered_map操作平均为O(1)
 * 空间复杂度：O(n),使用了一个unordered_map容器，空间复杂度为O(n)
 * @param array 目标数组
 * @param len 数组长度
 * @return int 主元素或-1
 */
int mainElementII(int array[], int len) {
  // 统计数组中各个元素出现次数
  unordered_map<int, int> map;
  for (int i = 0; i < len; i++) {
    map[array[i]]++;
  }

  // 遍历哈希表，如果元素出现次数大于数组长度一半则返回
  for (auto e : map) {
    if (e.second > len / 2) {
      return e.first;
    }
  }
  // 没有主元素，返回-1
  return -1;
}

/**
 * @brief 暴力解法
 * 算法思想：遍历数组每个元素，计算每个元素出现次数
 * 时间复杂度：O(n^2),2个嵌套for循环
 * 空间复杂度：O(1)，只使用了两个局部变量
 */
int mainElementIII(int array[], int len) {
  for (int i = 0; i < len; i++) {
    int count = 0; // 元素个数
    int number = array[i];
    for (int j = 0; j < len; j++) {
      if (array[j] == number) {
        count++;
      }
    }
    if (count > len / 2) {
      return number;
    }
  }

  return -1;
}
