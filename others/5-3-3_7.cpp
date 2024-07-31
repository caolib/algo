/**
 * @date 2024-07-31
 * @brief 计算二叉树中双分支结点的个数
 */

#include "../treeUtils.h"

int nodeNumber(BTree *t) {
  if (t == nullptr)
    return 0;
  return t->left != nullptr && t->right != nullptr
             ? nodeNumber(t->left) + nodeNumber(t->right) + 1
             : nodeNumber(t->left) + nodeNumber(t->right);
}

int main() {
  // Create a binary tree
  BTree *tree = new BTree();
  tree->left = new BTree();
  tree->right = new BTree();
  tree->left->left = new BTree();
  tree->left->right = new BTree();
  tree->right->left = new BTree();
  tree->right->right = new BTree();

  // Calculate the number of double branch nodes
  int result = nodeNumber(tree);

  // Print the result 3个
  std::cout << "Number of double branch nodes: " << result << std::endl;

  // Clean up memory
  delete tree->left->left;
  delete tree->left->right;
  delete tree->right->left;
  delete tree->right->right;
  delete tree->left;
  delete tree->right;
  delete tree;

  return 0;
}