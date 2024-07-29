/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-29
 * 二叉树
 */

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Tree;

Tree *createBinaryTree() {
  Tree *root = new Tree;
  root->data = 1;

  Tree *node2 = new Tree;
  node2->data = 2;

  Tree *node3 = new Tree;
  node3->data = 3;

  Tree *node4 = new Tree;
  node4->data = 4;

  Tree *node5 = new Tree;
  node5->data = 5;

  root->left = node2;
  root->right = node3;
  node2->left = node4;
  node2->right = nullptr;
  node3->left = nullptr;
  node3->right = node5;
  node4->left = nullptr;
  node4->right = nullptr;
  node5->left = nullptr;
  node5->right = nullptr;

  return root;
}
