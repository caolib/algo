/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-29
 * 树的遍历
 */
#include "iostream"
#include "tree.h"
#include <functional>
#include <vector>
using namespace std;
void test(function<void(Tree *)> f);

/**
 * 先序遍历
 * @param t 树
 */
void preOrder(Tree *t) {
  if (t == nullptr)
    return;
  cout << t->data << " ";
  preOrder(t->left);
  preOrder(t->right);
}

/**
 * 中序遍历
 * @param t 树
 */
void midOrder(Tree *t) {
  if (t == nullptr)
    return;
  midOrder(t->left);
  cout << t->data << " ";
  midOrder(t->right);
}

/**
 * 后序遍历
 * @param t 树
 */
void afterOrder(Tree *t) {
  if (t == nullptr)
    return;
  afterOrder(t->left);
  afterOrder(t->right);
  cout << t->data << " ";
}

int main() {

  test(preOrder);
  test(midOrder);
  test(afterOrder);

  return 0;
}

void test(function<void(Tree *)> f) {
  Tree t1;
  t1.data = 1;
  // 多添加几个节点
  Tree t2;
  t2.data = 2;
  Tree t3;
  t3.data = 3;
  Tree t4;
  t4.data = 4;
  Tree t5;
  t5.data = 5;
  t1.left = &t2;
  t1.right = &t3;
  t2.left = &t4;
  t2.right = nullptr;
  t3.left = nullptr;
  t3.right = &t5;
  t4.left = nullptr;
  t4.right = nullptr;
  t5.left = nullptr;
  t5.right = nullptr;
  cout << "[ ";
  f(&t1);
  cout << "]" << endl;
}
