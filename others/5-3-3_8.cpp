/**
 * @author libin (1265501579@qq.com)
 * @date 2024-07-31
 * @brief 将二叉树所有左右子树交换位置
 */

#include "../treeUtils.h"
void changeChild(BTreeII *t) {
  if (t == nullptr)
    return;
  BTreeII *n = t->left;
  t->left = t->right;
  t->right = n;
  changeChild(t->left);
  changeChild(t->right);
}

int main() {
  // Create a binary tree
  BTreeII *root = nullptr;
  root = new BTreeII;
  root->weight = 1;
  root->left = nullptr;
  root->right = nullptr;

  root->left = new BTreeII;
  root->left->weight = 2;
  root->left->left = nullptr;
  root->left->right = nullptr;

  root->left->left = new BTreeII;
  root->left->left->weight = 4;
  root->left->left->left = nullptr;
  root->left->left->right = nullptr;

  root->left->right = new BTreeII;
  root->left->right->weight = 5;
  root->left->right->left = nullptr;
  root->left->right->right = nullptr;

  root->right = new BTreeII;
  root->right->weight = 3;
  root->right->left = nullptr;
  root->right->right = nullptr;

  root->right->left = new BTreeII;
  root->right->left->weight = 6;
  root->right->left->left = nullptr;
  root->right->left->right = nullptr;

  root->right->right = new BTreeII;
  root->right->right->weight = 7;
  root->right->right->left = nullptr;
  root->right->right->right = nullptr;

  // Print the original binary tree
  std::cout << "Original Binary Tree:" << std::endl;
  printTree(root);

  // Change the child nodes of the binary tree
  changeChild(root);

  // Print the modified binary tree
  std::cout << "Modified Binary Tree:" << std::endl;
  printTree(root);

  // Clean up the memory
  deleteTree(root);

  return 0;
}