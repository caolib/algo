#include "./2014.h"
#include "./2017.h"
#include "./treeUtils.h"

void test2014() {
  // 创建二叉树
  BTreeII *root = new BTreeII();
  root->weight = 1;

  BTreeII *leftChild = new BTreeII();
  leftChild->weight = 2;

  BTreeII *rightChild = new BTreeII();
  rightChild->weight = 8;

  BTreeII *r2 = new BTreeII();
  r2->weight = 2;

  root->left = leftChild;
  root->right = rightChild;
  rightChild->right = r2;

  // 计算二叉树的带权路径长度
  int wpl = WPL(root);

  // 输出结果
  std::cout << "The weighted path length of the binary tree is: " << wpl
            << std::endl;

  // 释放内存
  delete root;
  delete leftChild;
  delete rightChild;
}

void test2017() {
  inOrder(createExpressionTree(), true);
  cout << endl;
  inOrder(createExpressionTreeII(), true);
}

int main() {

  test2014();

  // test2017();

  return 0;
}