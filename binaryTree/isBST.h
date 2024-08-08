/**
 * @author libin (1265501579@qq.com)
 * @date 2024-08-08
 *
 * @brief 判断二叉树是否为二叉排序树
 * 错误做法：遍历每个节点判断左<根<右 ×
 */
#include <climits> // 包含 INT_MIN

// 二叉树的结点结构
typedef struct BiTNode {
  int data;                        // 结点数据
  struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

int tempMax;
bool isBST;

void inOrder(BiTree t) {
  if (t == nullptr)
    return;
  inOrder(t->lchild);
  if (t->data > tempMax)
    tempMax = t->data;
  else {
    isBST = false;
    return;
  }
  inOrder(t->rchild);
}

bool checkBST(BiTree t) {
  tempMax = INT_MIN; // 初始化为 int 类型最小值
  isBST = true;
  inOrder(t);
  return isBST;
}