/**
 * @author libin (1265501579@qq.com)
 * @date 2024-08-08
 * 判断一棵树是否是平衡二叉树
 */

bool isBalance;
// 二叉树的结点结构
typedef struct BiTNode {
  int data;                        // 结点数据
  struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 判断一棵树是否是平衡二叉树
int postOrder(BiTree T) {
  if (T == nullptr) {
    return 0;
  }
  int left = postOrder(T->lchild);
  int right = postOrder(T->rchild);
  if (left - right > 1 || right - left > 1)
    isBalance = false;

  return left > right ? left + 1 : right + 1;
}

bool isBalanceTree(BiTree T) {
  isBalance = true;
  postOrder(T);
  return isBalance;
}