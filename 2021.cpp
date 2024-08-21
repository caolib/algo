/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-26
 * @brief 如果图中度数为奇数的顶点为0或2个，返回1，否则返回0
 * @paragraph
 * 算法思想：
 * 1.遍历所有顶点，统计度数为奇数的顶点个数，如果个数为0或2返回1，否则返回0
 * 2.无向图中，顶点的度数即为连接该顶点的边数
 * 3.邻接矩阵表示法中每行非0元素个数即为即为连接顶点的边数
 */
#include <iostream>
using namespace std;
#define MAXV 100
typedef struct {
  int numVertices, numEdges; // 图的顶点数和有向边数
  char VerticesList[MAXV];   // 顶点表，MAXV为已定义常量
  int Edge[MAXV][MAXV];      // 邻接矩阵
} MGraph;

int isExistEL(MGraph m) {
  int count = 0, v = m.numVertices; // count:度数为1的顶点个数
  for (int i = 0; i < v; i++) {
    int degree = 0; // 顶点度数
    for (int j = 0; j < v; j++)
      if (m.Edge[i][j] != 0)
        degree++;
    if (degree % 2 == 0) {
      count++;
      if (count > 2)
        return 0;
    }
  }
  if (count == 1)
    return 0;
  return 1;
}

int main() {
  MGraph graph;
  graph.numVertices = 4;
  graph.numEdges = 6;
  graph.VerticesList[0] = 'A';
  graph.VerticesList[1] = 'B';
  graph.VerticesList[2] = 'C';
  graph.VerticesList[3] = 'D';

  // Initialize the adjacency matrix
  for (int i = 0; i < graph.numVertices; i++) {
    for (int j = 0; j < graph.numVertices; j++) {
      graph.Edge[i][j] = 0;
    }
  }

  // Add edges to the adjacency matrix
  graph.Edge[0][1] = 1;
  graph.Edge[0][3] = 1;
  graph.Edge[1][0] = 1;
  graph.Edge[1][2] = 1;
  graph.Edge[1][3] = 1;
  graph.Edge[2][1] = 1;
  graph.Edge[2][3] = 1;
  graph.Edge[3][0] = 1;
  graph.Edge[3][1] = 1;
  graph.Edge[3][2] = 1;

  cout << isExistEL(graph) << endl;

  return 0;
}