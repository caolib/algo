#pragma once
#include <iostream>

/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-08
 */

using namespace std;
/**
 * @brief 打印数组
 * @param arr 数组
 * @param len 数组长度
 */
void print(int arr[], int len) {
  cout << "[ ";
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << "]" << endl;
}

void print(int arr[], int low, int high) {
  cout << "[ ";
  for (int i = low; i < high; i++) {
    cout << arr[i] << " ";
  }
  cout << "]" << endl;
}

/**
 * @brief 二分查找
 * @param a 有序数组
 * @param size 数组大小
 * @param e 目标元素
 * @return int 找到 -> 目标元素索引;没找到 -> 目标元素应该插入的位置
 */
int binarySearch(int a[], int size, int e) {
  int left = 0, right = size - 1;
  int mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (a[mid] == e) {
      return mid;
    }
    if (e < a[mid]) {
      right = mid - 1;
    } else if (e > a[mid]) {
      left = mid + 1;
    }
  }
  return -left - 1;
}

/**
 * @brief 打印邻接表
 * @param graph 图的邻接矩阵
 */
#define MAXV 100
typedef struct {
  int numVertices, numEdges; // 图的顶点数和有向边数
  char VerticesList[MAXV];   // 顶点表，MAXV为已定义常量
  int Edge[MAXV][MAXV];      // 邻接矩阵
} MGraph;
void printGraph(MGraph graph) {
  // 打印顶点列表
  cout << "  ";
  for (int i = 0; i < graph.numVertices; i++) {
    std::cout << graph.VerticesList[i] << " ";
  }
  std::cout << std::endl;

  // 打印邻接矩阵
  for (int i = 0; i < graph.numVertices; i++) {
    // 打印行首的顶点
    std::cout << graph.VerticesList[i] << " ";
    for (int j = 0; j < graph.numVertices; j++) {
      std::cout << graph.Edge[i][j] << " ";
    }
    std::cout << std::endl;
  }
}