#pragma once
#include <unordered_map>
using namespace std;
/**
 * @brief [2013 统考真题] 如果一个数组(数组元素 > 0)中某个元素出现次数 >
 * 数组长度的一半,则该元素是数组的主元素。设计算法找出一个数组的主元素，如果没有返回-1
 * @author clb (1265501579@qq.com)
 * @date 2024-07-14
 * @paragraph
 * 算法思想：使用哈希表统计数组中每个数出现的次数，遍历哈希表找出主元素
 * 时间复杂度：O(n),2个单层for循环;unordered_map操作平均为O(1)
 * 空间复杂度：O(n),使用了一个unordered_map容器，空间复杂度为O(n)
 * @param array 目标数组
 * @param len 数组长度
 * @return int 主元素或-1
 */
int mainElement(int array[], int len) {
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