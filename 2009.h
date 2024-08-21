#include "linkUtils.h"

/**
 * @brief  [2009统考真题] 假设单链表只给出了头指针1ist。在不改变链表的前提下
 * <找出链表倒数第k个位置上的结点>若查找成功，算法输出该结点的data域的值，并返回1；否则，只返回0
 * @author clb (1265501579@qq.com)
 * @date 2024-07-16
 * @paragraph
 * 算法思想：
 * 1.遍历单链表，统计节点个数count
 * 2.如果k大于count，查找失败，返回0
 * 3.目标节点前有count-k个结点，所以需要从头结点开始向后移动count-k+1个位置找到目标节点输出data，返回1
 * 时间复杂度 O(n)
 * 空间复杂度 O(1)
 */
int findNode(LinkList list, int k) {
  // 统计节点总数count
  int count = 0;
  LinkNode *p = list;
  while (p->link != nullptr) {
    count++;
    p = p->link;
  }
  // 如果k大于count，必定查找失败
  if (k > count) {
    return 0;
  }

  // count-k就是要找的节点数前面节点个数,+1后就是目标节点
  count = count - k + 1;
  p = list;
  while (count > 0) {
    p = p->link;
    count--;
  }

  if (p != nullptr) {
    cout << "结点值为:" << p->data;
    return 1;
  }
  return 0;
}

int findNode(LinkList list, int k) {
  LinkNode *p = list;
  LinkNode *q = list;
  // q先走k步
  for (int i = 0; i < k; i++) {
    if (q->link != nullptr) {
      q = q->link;
    } else {
      return 0;
    }
  }
  // q和p一起走，直到q走到链表尾部
  while (q->link != nullptr) {
    p = p->link;
    q = q->link;
  }
  cout << "结点值为:" << p->data;
  return 1;
}