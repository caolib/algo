/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-22
 * @brief 将表达式二叉树转换为等价的中缀表达式(通过括号反应操作符的计算次序)
 * @paragraph
 * 算法思想：中序遍历二叉树，使用deep区别是否为根节点(最外层不需要括号)
 * 在遍历左子树前和遍历完右子树后需要输出左右括号，除非是叶节点
 * 时间复杂度：O(n)
 * 空间复杂度：O(h),h为树的高度
 */
#include "./treeUtils.h"

void inOrder(BTree *root, int deep) {
  if (root == nullptr) return;
  bool flag = (root->left != nullptr || root->right != nullptr) && (deep != 1);
  if (flag) cout << "(";
  
  inOrder(root->left, deep + 1);
  cout << root->data;
  inOrder(root->right, deep + 1);
  if (flag) cout << ")";
}


void midOrder(BTree *t){
  if(t==nullptr) return;
  bool isLeaf = t->left == nullptr && t->right == nullptr;
  if(!isLeaf) cout<<"(";
  midOrder(t->left);
  cout<<t->data;
  midOrder(t->right);
  if(!isLeaf) cout<<")";
}

void func(BTree *root){
  if(root==nullptr)return;
  midOrder(root->left);
  cout<<root->data;
  midOrder(root->right);
}
