/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-22
 * @brief 求二叉树的带权路径长度(WPL,所有叶节点的带权路径长度)
 * 二叉树的WPL等于其左右子树的WPL之和
 * 1.如果左右子树都为空，返回当前结点的 权值×深度
 * 2.如果左右子树不都为空，返回左右子树的WPL之和
 */
#pragma once
#include "./treeUtils.h"
#include <iostream>
using namespace std;

// 根据设计思想，采用C或C++语言描述算法，关键之处给出注释

int getWPL(BTreeII *t, int deep) { // deep为结点的深度
  if (t == nullptr)
    return 0;
  if (t->left == nullptr && t->right == nullptr) { // 是叶子节点
    return t->weight * deep;
  }
  return getWPL(t->left, deep + 1) + getWPL(t->right, deep + 1);
}

int WPL(BTreeII *t) { return getWPL(t, 0); }
