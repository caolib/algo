#pragma once
#include "./linkUtils.h"
/**
 * @brief [2019 统考真题]
 * 设线性表L=(a1,a2,a3......an)采用带头结点的单链表保存,将单链表重新排列为(a1,an,a2,an-1......)
 * 要求:空间复杂度为O(1)
 * @author clb (1265501579@qq.com)
 * @date 2024-07-18
 * 算法思想：
 * 1.使用快慢指针找到链表中间节点(偶数个则为中间后一个)，每次快指针走2步，慢指针走1步
 * 2.将慢指针后半部分链表逆置
 * 3.将逆置后的链表插入到未逆置的前半部分链表中
 * 4.算法结束，返回头指针
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

LinkList refactorLink(LinkList head) {
  // 快慢指针找到链表中点
  LinkList quick, slow;
  quick = head->link;
  slow = head->link;
  while (quick != nullptr && quick->link != nullptr) {
    quick = quick->link->link;
    slow = slow->link;
  }

  // 逆置慢指针后半部分链表
  LinkList p = slow->link;
  slow->link = nullptr;
  while (p != nullptr) {
    LinkList node = p;
    p = p->link;
    node->link = slow;
    slow = node;
  }
  // 将逆置后的链表结点插入到前半部分
  LinkList h = head->link;
  while (slow != nullptr) {
    LinkList ins = slow;
    slow = slow->link;
    if (slow == nullptr) {
      break;
    }
    ins->link = h->link;
    h->link = ins;
    h = ins->link;
  }
  return head;
}