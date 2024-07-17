#include "linkUtils.h"
/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-17
 * @brief [2012 统考真题]
 * 两个带头结点的单链表有一段共同的后缀链表，找出共同后缀起始位置的那个节点
 * @paragraph
 * 算法思想：
 * 1.设str1前半段长度为a,str2前半段长度为b,共同后缀长度为c
 * 2.使用两个指针p1、p2分别遍历l1、l2,
 * 3.当p1走到链表尾端时，p1走了a+c,然后让p1跳到l2的头部(长为b)
 * 4.当p2走到链表尾端时，p2走了b+c,然后让p2跳到l1的头部(长为a)
 * 5.p1、p2必定在交叉节点处相遇，p1、p2走的长度都是a+b+c
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

LinkList findCross(LinkList str1, LinkList str2) {
  // 初始化两个指针分别指向两个链表的头结点
  LinkList p1 = str1;
  LinkList p2 = str2;

  while (1) {
    // 如果p1(p2)指针走到尽头跳转到链表2(1)的头部,否则沿当前链表走
    if (p1->link == nullptr) {
      p1 = str2->link;
    } else {
      p1 = p1->link;
    }
    if (p2->link == nullptr) {
      p2 = str1->link;
    } else {
      p2 = p2->link;
    }
    if (p1 == p2) { // 两个指针指向同一个结点，即为交叉结点
      return p1;
    }
  }
}