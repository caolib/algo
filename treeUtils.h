#pragma once
#include <cstring>
#include <iostream>
using namespace std;

typedef struct node {
  char data[10];
  struct node *left, *right;
} BTree;

// 创建新节点的函数
BTree *newNode(const char *val) {
  BTree *node = new BTree;
  strcpy(node->data, val);            // 复制值到节点
  node->left = node->right = nullptr; // 初始化左右子节点为nullptr
  return node;
}

// 构建并返回表达式树的函数
BTree *createExpressionTree() {
  // 构建表达式树
  BTree *root = newNode("*"); // 根节点是乘法操作

  // 构建左子树 (a+b)
  root->left = newNode("+");
  root->left->left = newNode("a");
  root->left->right = newNode("b");

  // 构建右子树 c*(-d)
  root->right = newNode("*");
  root->right->left = newNode("c");
  root->right->right = newNode("-");
  root->right->right->right = newNode("d");

  return root; // 返回构建完成的树的根节点
}

// 构建并返回表达式树的函数
BTree *createExpressionTreeII() {

  // 构建另一个表达式 (a+b)+(-(c-d))
  BTree *expressionTree = newNode("+"); // 根节点是加法操作

  // 构建左子树 (a+b)
  expressionTree->left = newNode("*");
  expressionTree->left->left = newNode("a");
  expressionTree->left->right = newNode("b");

  // 构建右子树 (-(c-d))
  expressionTree->right = newNode("-");
  expressionTree->right->right = newNode("-");
  expressionTree->right->right->left = newNode("c");
  expressionTree->right->right->right = newNode("d");

  return expressionTree; // 返回构建完成的树的根节点
}
