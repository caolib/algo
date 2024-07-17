/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-16
 */
#include "2009.h"
#include "2012.h"
#include "func.h"
#include <functional>

void runFindNode(LinkList list, int k, function<int(LinkList, int)> function) {
  int result = function(list, k);
  if (result) {
    cout << "\t[查找成功]\n";
    return;
  }
  cout << result << "\t\t[查找失败]\n";
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
  // 将l2的2指向l1的5，交叉点为5
  l2->link->link->link = l1->link->link->link->link->link;

  printLinkedList(l1);
  printLinkedList(l2);

  LinkList node = findCross(l1, l2);
  cout << "交叉节点:" << node->data << endl;

  deleteLinkedList(l1);
  deleteLinkedList(l2);
}
int main() {

  // testFindNode();

  testFindCross();

  return 0;
}
