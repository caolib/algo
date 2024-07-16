/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-16
 */
#include "2009.h"
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
}

int main() {

  testFindNode();

  return 0;
}
