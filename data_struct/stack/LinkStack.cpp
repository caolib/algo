/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-24
 * 基于链式存储的栈，使用单链表实现，栈顶在链头(不带头结点)
 */

#include <iostream>
using namespace std;

typedef struct Node {
  int data;
  struct Node *next = nullptr;
} LinkStack, *LStack;

bool isEmpty(LStack l) { return l == nullptr; }

void push(LStack &l, int data) {
  LinkStack *node = new LinkStack;
  node->data = data;
  if (isEmpty(l)) { // 空栈时
    l = node;
    return;
  }
  node->next = l;
  l = node;
}

int pop(LStack &l) {
  if (isEmpty(l)) {
    throw runtime_error("栈为空，不允许出栈！");
  }
  LinkStack *node = l;
  int data = node->data;
  if (l->next == nullptr) { // 最后一个节点时
    l = nullptr;
  } else {
    l = l->next;
  }
  delete node;
  return data;
}

int main() {
  LStack stack = nullptr;
  // 测试 isEmpty
  cout << "栈应该是空的: " << isEmpty(stack) << endl;

  // 向栈中 push 元素
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);

  // 检查栈是否仍然为空
  cout << "栈现在应该不为空: " << isEmpty(stack) << endl;

  // pop 元素并检查
  cout << "Pop 元素: " << pop(stack) << " 应该是 3" << endl;
  cout << "Pop 元素: " << pop(stack) << " 应该是 2" << endl;

  // 尝试从空栈中 pop 元素
  try {
    while (!isEmpty(stack)) {
      cout << "Pop 元素: " << pop(stack) << endl;
    }
    pop(stack); // 这里应该抛出异常
  } catch (const runtime_error &e) {
    cout << "捕获异常: " << e.what() << endl;
  }

  // 最后检查栈的状态
  cout << "栈应该是空的: " << isEmpty(stack) << endl;

  return 0;
}
