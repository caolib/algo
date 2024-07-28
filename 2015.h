#include "linkUtils.h"
/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-18
 * @brief [2012 统考真题]
 * 用单链表保存m个整数，结点的结构为[data][link]，且|data|≤
 * n（n为正整数）。现要求设计一个时间复杂度尽可能高效的算法，对于链表中data的绝对值相等的结点，
 * 仅保留第一次出现的结点而删除其余绝对值相等的结点
 * @paragraph
 * 算法思想：
 * 1.使用一个bool数组(索引为数，值为True/False)记录对应的数是否已经出现(因为数据给了最大范围，所以一个a[n+1]数组就能统计所有可能数据)
 * 2.使用双指针遍历单链表，pre为p指针前驱，每次循环p根据bool数组判断当前数字是否已经存在
 *    2.1 如果不存在，将当前数据标记为存在，双指针指针都向后移动
 *    2.2 如果存在，p指针向后移动，直到移动到的数字为不存在或移动到了尾部,
 *        保存pre的下一个结点，然后将pre指向p指针，并将保存的结点及后续结点全部删除
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * @param m 节点个数
 * @param n 数据绝对值最大值，正整数
 */
LinkList deleteSameNode(LinkList head, int n) {
  bool flag[n + 1]; // 数据是否已经出现，索引为0~n
  for (int i = 0; i < n + 1; i++) {
    flag[i] = false;
  }

  LinkList pre = head;
  LinkList p = pre->link;
  while (p != nullptr) {
    int data = p->data >= 0 ? p->data : -p->data; // 取绝对值
    if (flag[data]) {                             // 如果已经存在
      LinkList node = p;                          // 保存结点，便于删除
      while (p != nullptr) { // 指针后移，直到找到不存在或到链尾
        int pdata = p->data >= 0 ? p->data : -p->data;
        if (!flag[pdata]) {
          break;
        }
        p = p->link;
      }
      pre->link = p; // 将前驱指针指向当前p所在位置(跳过了上个结点)

      deleteLinkedList(node);
    } else { // 如果不存在
      flag[data] = true;
    }
    if (p == nullptr) {
      break;
    }
    p = p->link;
    pre = pre->link;
  }
  return head;
}