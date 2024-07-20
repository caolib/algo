#include "../linkUtils.h"

/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-20
 * @brief 从两个升序单链表A,B中提取公共元素形成单链表C,要求不破坏A,B结点
 */
LinkList collectSame(LinkList a, LinkList b) {
  LinkList c = new LinkNode;
  LinkList p1 = a->link, p2 = b->link, p3 = c;

  while (p1 != nullptr && p2 != nullptr) {
    if (p1->data == p2->data) { // 如果是公共元素 => 插入到c，三指针同时后移
      LinkList node = new LinkNode;
      node->link = nullptr;
      node->data = p1->data;
      p3->link = node;
      p3 = p3->link;
      p1 = p1->link;
      p2 = p2->link;
      continue;
    }
    // 如果不是公共元素，元素值小的指针向后移
    if (p1->data < p2->data) {
      p1 = p1->link;
    } else {
      p2 = p2->link;
    }
  }
  return c;
}

int main() {
  int a[] = {1, 2, 3, 4, 5};
  LinkList la = geneLinkedList(a, sizeof(a) / sizeof(a[0]));
  int b[] = {1, 3, 5, 7};
  LinkList lb = geneLinkedList(b, sizeof(b) / sizeof(b[0]));

  printLinkedList(la);
  printLinkedList(lb);
  LinkList c = collectSame(la, lb);
  printLinkedList(c);

  deleteLinkedList(la);
  deleteLinkedList(lb);
  deleteLinkedList(c);
  return 0;
}
