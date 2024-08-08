/**
 * @author libin (1265501579@qq.com)
 * @date 2024-08-08
 */
#include <algorithm> // for std::max
#include <iostream>
using namespace std;

// 二叉树的结点结构
typedef struct BiTNode {
  int data;                        // 结点数据
  struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 计算二叉树的高度
int height(BiTree t) {
  if (t == nullptr)
    return 0;

  int lh = height(t->lchild);
  int rh = height(t->rchild);

  return std::max(lh, rh) + 1;
}

// 计算二叉树的最大宽度
int width[1024]; // 保存每层的结点数
void maxWidth(BiTree t, int level) {
  if (t == nullptr)
    return;
  width[level]++; // 记录当前层的结点数
  maxWidth(t->lchild, level + 1);
  maxWidth(t->rchild, level + 1);
}

// 二叉树的最大宽度
int maxWidth(BiTree t) {
  for (int i = 0; i < 1024; i++)
    width[i] = 0;
  maxWidth(t, 1);
  int max = 0;
  for (int i = 0; i < 1024; i++)
    if (width[i] > max)
      max = width[i];
  return max;
}

// 计算二叉树的WPL
int WPL(BiTree t, int level) {
  if (t == nullptr)
    return 0;
  if (t->lchild == nullptr && t->rchild == nullptr)
    return t->data * level;
  int lWPL = WPL(t->lchild, level + 1);
  int rWPL = WPL(t->rchild, level + 1);
  return lWPL + rWPL;
}

int WPL(BiTree t) { return WPL(t, 0); }

int main() {
  BiTree tree = nullptr;

  // Create a binary tree
  BiTNode *node1 = new BiTNode;
  node1->data = 1;
  node1->lchild = nullptr;
  node1->rchild = nullptr;

  BiTNode *node2 = new BiTNode;
  node2->data = 2;
  node2->lchild = nullptr;
  node2->rchild = nullptr;

  BiTNode *node3 = new BiTNode;
  node3->data = 3;
  node3->lchild = nullptr;
  node3->rchild = nullptr;

  BiTNode *node4 = new BiTNode;
  node4->data = 4;
  node4->lchild = nullptr;
  node4->rchild = nullptr;

  BiTNode *node5 = new BiTNode;
  node5->data = 5;
  node5->lchild = nullptr;
  node5->rchild = nullptr;

  node1->lchild = node2;
  node1->rchild = node3;
  node2->lchild = node4;
  node3->rchild = node5;

  tree = node1;

  // Calculate the height of the binary tree
  int treeHeight = height(tree);
  std::cout << "高度:" << treeHeight << std::endl;
}