#include "../linkUtils.h"

/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-20
 * @brief
 * 设C={a，b1,a2,b2,...an,bn}为线性表，采用带头结点的单链表存放，设计一个就地算法,
 * 将其拆分为两个单链表，使得A={a,a2,...an}，B={b1,b2,...bn}
 */
void takeApartLink(LinkList head) {
  printLinkedList(head);
  LinkList p1 = head->link;
  LinkList p2 = new LinkNode;
  LinkList head2 = p2;
  while (p1->link != nullptr) {
    p2->link = p1->link;
    p2 = p2->link;
    p1->link = p2->link;
    if (p1 == nullptr || p1->link == nullptr) {
      break;
    }
    p1 = p1->link;
  }
  p2->link = nullptr;
  printLinkedList(head);
  printLinkedList(head2);

  delete (p2);
  delete (head2);
}

int main() {
  int a[] = {1, 11, 2, 12, 3, 13, 4};
  LinkList head = geneLinkedList(a, sizeof(a) / sizeof(a[0]));

  takeApartLink(head);

  deleteLinkedList(head);
  return 0;
}
