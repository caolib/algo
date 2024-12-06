/**
 * @author clb (1265501579@qq.com)
 * @date 2024-12-06 15:46:55
 * @brief [2022] 判断一棵使用顺序数组保存的二叉树是否为二叉排序树
 * 算法思想：二叉排序树的中序遍历是一个递增的序列
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
#include <iostream>
#define MAX_SIZE 100

typedef struct {
  int SqBiTNode[MAX_SIZE];
  int ElemNum;
} SqBiTree;

bool isBSTUtil(SqBiTree tree, int index, int *prev) {
  if (index >= tree.ElemNum || tree.SqBiTNode[index] == -1) {
    return true;
  }

  // 左子树
  if (!isBSTUtil(tree, 2 * index + 1, prev)) {
    return false;
  }

  // 当前节点
  if (tree.SqBiTNode[index] <= *prev) {
    return false;
  }
  *prev = tree.SqBiTNode[index];

  // 右子树
  return isBSTUtil(tree, 2 * index + 2, prev);
}

bool isBST(SqBiTree tree) {
  int prev = -__INT_MAX__;
  return isBSTUtil(tree, 0, &prev);
}

int main() {
  SqBiTree tree = {
      .SqBiTNode = {4, 2, 6, 1, 3, 5, 7}, // 完全二叉树数组表示
      .ElemNum = 7                         // 有效节点数
  };

  SqBiTree tree2 = {
      .SqBiTNode = {20,-1,50,-1,-1,10}, // 完全二叉树数组表示
      .ElemNum = 7                         // 有效节点数
  };

  if (isBST(tree)) {
    printf("该二叉树是BST。\n");
  } else {
    printf("该二叉树不是BST。\n");
  }

  
  if (isBST(tree2)) {
    printf("该二叉树是BST。\n");
  } else {
    printf("该二叉树不是BST。\n");
  }

  return 0;
}
