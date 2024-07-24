/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-24
 * @brief 顺序存储的栈
 */
#include <iostream>
#include <stdexcept>
using namespace std;
#define MAXSIZE 100
typedef struct {
  int data[MAXSIZE];
  int top = -1;
  bool push(int data); // 入栈
  int pop();           // 出栈
  bool isEmpty();      // 判空
  bool isFull();       // 判满
  int getTop();        // 获取栈顶元素
} SqStack;

bool SqStack::isEmpty() { return top == -1; }

bool SqStack::isFull() { return top == MAXSIZE - 1; }

bool SqStack::push(int d) {
  if (isFull()) {
    cerr << "栈已满！" << endl;
    return false;
  }
  data[++top] = d;
  return true;
}

int SqStack::pop() {
  if (isEmpty()) {
    throw runtime_error("栈为空，不允许出栈！");
  }
  return data[top--];
}

int main() {
  SqStack stack;
  // 测试 isEmpty
  cout << "栈应该是空的: " << stack.isEmpty() << endl;

  // 向栈中 push 元素
  stack.push(1);
  stack.push(2);
  stack.push(3);

  // 检查栈是否仍然为空
  cout << "栈现在应该不为空: " << stack.isEmpty() << endl;

  // 检查栈是否已满
  cout << "栈应该不是满的: " << stack.isFull() << endl;

  // pop 元素并检查
  cout << "Pop 元素: " << stack.pop() << " 应该是 3" << endl;
  cout << "Pop 元素: " << stack.pop() << " 应该是 2" << endl;

  // 尝试从空栈中 pop 元素
  try {
    while (!stack.isEmpty()) {
      cout << "Pop 元素: " << stack.pop() << endl;
    }
    stack.pop(); // 这里应该抛出异常
  } catch (const runtime_error &e) {
    cout << "捕获异常: " << e.what() << endl;
  }

  // 最后检查栈的状态
  cout << "栈应该是空的: " << stack.isEmpty() << endl;
  cout << "栈应该不是满的: " << stack.isFull() << endl;

  return 0;
}