#include "../linkUtils.h"

/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-20
 * @brief 删除一个升序单链表(假设带头结点)中所有重复出现的元素
 * 素，例如[7,10,10,21,30,42,42,42,51,70]将变为[7,10,21,30,42,51,70]
 */
void removeSame(LinkList head) {
  LinkList pre = head, next = head->link;
  if (next == nullptr)
    return;
  while (next != nullptr) {
    if (next->data == pre->data) { // 如果是重复结点
      while (next != nullptr) {
        next = next->link;
        if (next == nullptr) { // 走到链尾，直接退出
          pre->link = nullptr;
          return;
        }
        if (next->data != pre->data) { // 跳过中间重复结点
          pre->link = next;
          break;
        }
      }
    }
    // 不是重复结点就同时后移
    pre = pre->link;
    next = next->link;
  }
}

int main() {
  int a[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70, 70, 70};
  LinkList head = geneLinkedList(a, sizeof(a) / sizeof(a[0]));

  printLinkedList(head);
  removeSame(head);
  printLinkedList(head);

  deleteLinkedList(head);
  return 0;
}
