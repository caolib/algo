#include "../linkUtils.h"

/**
 * @brief 逆置带有头结点的单链表 [1->2->3] => [3->2->1]
 * @author clb (1265501579@qq.com)
 * @date 2024-07-19
 * @paragraph
 * 思路：额外定义一个指针p指向头指针的下一个结点，将头指针置为空，
 * p遍历链表，遍历过的节点使用 [头插法] 插入到head之后，实现逆置
 * 时间复杂度:O(n)
 * 空间复杂度O(1)
 */
LinkList reverseLink(LinkList head) {
  LinkList p = head->link;
  head->link = nullptr;
  while (p != nullptr) {
    LinkNode *node = p;
    p = p->link;
    node->link = head->link;
    head->link = node;
  }

  return head;
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 3, 4, 5};
  LinkList head = geneLinkedList(a, sizeof(a) / sizeof(a[0]));
  printLinkedList(head);

  reverseLink(head);

  printLinkedList(head);

  deleteLinkedList(head);

  return 0;
}
