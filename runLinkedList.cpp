/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-16
 */
#include "2009.h"
#include "2012.h"
#include "2015.h"
#include "2019.h"
#include "func.h"
#include <functional>

void runFindNode(LinkList list, int k, function<int(LinkList, int)> function) {
  int result = function(list, k);
  if (result) {
    cout << "\t[成功]\n";
    return;
  }
  cout << result << "\t\t[失败]\n";
}

void testFindNode() {
  LinkList list = geneLinkedList();
  printLinkedList(list);
  runFindNode(list, 1, findNode);
  runFindNode(list, 2, findNode);
  runFindNode(list, 4, findNode);
  runFindNode(list, 99, findNode);
  deleteLinkedList(list);
}

void testFindCross() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int arr2[] = {1, 2};
  LinkList l1 = geneLinkedList(arr, 7);
  LinkList l2 = geneLinkedList(arr2, 2);
  // 2->5
  l2->link->link->link = l1->link->link->link->link->link;

  printLinkedList(l1);
  printLinkedList(l2);

  LinkList node = findCross(l1, l2);
  cout << "结点为:" << node->data << endl;

  deleteLinkedList(l1);
  deleteLinkedList(l2);
}

void testDeleteSame() {
  // int arr[] = {21, -15, -15, -7, 15};
  int arr[] = {1, 0, 3, -1, 1, -1, 1, 1, 1, 1, 0};
  LinkList list = geneLinkedList(arr, 11);
  printLinkedList(list);
  list = deleteSameNode(list, 5, 50);
  printLinkedList(list);

  deleteLinkedList(list);
}

void testRefactorLink() {
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  LinkList head = geneLinkedList(a, 7);
  printLinkedList(head);

  refactorLink(head);

  printLinkedList(head);

  deleteLinkedList(head);
}
int main() {

  // testFindNode();

  // testFindCross();

  // testDeleteSame();

  testRefactorLink();
  return 0;
}
