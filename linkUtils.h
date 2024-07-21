#pragma once
#include <iostream>
using namespace std;
// 单链表节点
typedef struct LinkNode {
  int data;
  struct LinkNode *link;
} LinkNode, *LinkList;

LinkList geneLinkedList() {
  // 动态分配内存
  LinkNode *head = new LinkNode; // 头结点不赋值
  LinkNode *n1 = new LinkNode;
  LinkNode *n2 = new LinkNode;
  LinkNode *n3 = new LinkNode;
  LinkNode *n4 = new LinkNode;
  LinkNode *n5 = new LinkNode;

  // 初始化节点值
  n1->data = 1;
  n2->data = 2;
  n3->data = 3;
  n4->data = 4;
  n5->data = 5;

  // 构建链表
  head->link = n1;
  n1->link = n2;
  n2->link = n3;
  n3->link = n4;
  n4->link = n5;
  n5->link = nullptr; // 链表末尾

  return head;
}

LinkList geneLinkedList(int size) {
  // 动态分配内存
  LinkNode *head = new LinkNode; // 头结点不赋值
  LinkNode *n1 = new LinkNode;
  LinkNode *n2 = new LinkNode;
  LinkNode *n3 = new LinkNode;
  LinkNode *n4 = new LinkNode;
  LinkNode *n5 = new LinkNode;

  // 初始化节点值
  n1->data = 1;
  n2->data = 2;
  n3->data = 3;
  n4->data = 4;
  n5->data = 5;

  // 构建链表
  head->link = n1;
  n1->link = n2;
  n2->link = n3;
  n3->link = n4;
  n4->link = n5;
  n5->link = nullptr; // 链表末尾
  return head;
}

LinkList geneLinkedList(int arr[], int size) {
  if (size == 0)
    return nullptr; // 如果数组为空，则返回空指针

  LinkNode *head = new LinkNode; // 创建头结点
  LinkNode *current = head;

  for (int i = 0; i < size; ++i) {
    LinkNode *node = new LinkNode; // 为每个数组元素创建新节点
    node->data = arr[i];           // 初始化节点值
    current->link = node;          // 将当前节点链接到链表
    current = node;                // 移动到新的节点
  }

  current->link = nullptr; // 链表末尾
  return head;
}

// 打印单链表
void printLinkedList(LinkList head) {
  LinkNode *current = head->link;
  while (current != nullptr) {
    cout << current->data << " -> ";
    current = current->link;
  }
  cout << "null" << endl;
}

// 删除单链表
void deleteLinkedList(LinkList head) {
  LinkNode *current = head;
  while (current != nullptr) {
    LinkNode *next = current->link;
    delete current; // 释放当前节点占用的内存
    current = next; // 移动到下一个节点
  }
}