/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-25
 * @brief K顶点：出度大于入度的结点
 * 输出图中所有K顶点 并 返回K顶点个数
 *
 * @details
 * 算法思想：
 * - 遍历图中的每个顶点，判断其出度是否大于入度，如果是，输出该顶点，K顶点数+1
 * - 每行
 * - 返回K顶点集合的大小
 */

#include "func.h"
using namespace std;
/*
#define MAXV 100
typedef struct {
  int numVertices, numEdges; // 图的顶点数和有向边数
  char VerticesList[MAXV];   // 顶点表，MAXV为已定义常量
  int Edge[MAXV][MAXV];      // 邻接矩阵
} MGraph;
 */
int printVertices(MGraph m) {
  int v = m.numVertices; // 顶点数
  int k = 0;
  for (int i = 0; i < v; i++) {
    int in = 0, out = 0;
    // 统计出、入度
    for (int j = 0; j < v; j++) {
      if (i != j) {
        if (m.Edge[i][j] != 0)
          out++;
        if (m.Edge[j][i] != 0)
          in++;
      }
    }
    if (out > in) { // 出度大于入度，K顶点数+1，输出顶点
      k++;
      cout << m.VerticesList[i] << endl;
    }
  }
  return k;
}

int main() {
  MGraph graph;
  graph.numVertices = 5;
  graph.numEdges = 7;
  graph.VerticesList[0] = 'A';
  graph.VerticesList[1] = 'B';
  graph.VerticesList[2] = 'C';
  graph.VerticesList[3] = 'D';
  graph.VerticesList[4] = 'E';
  graph.Edge[0][1] = 1;
  graph.Edge[0][2] = 1;
  graph.Edge[1][2] = 1;
  graph.Edge[1][3] = 1;
  graph.Edge[2][3] = 1;
  graph.Edge[2][4] = 1;
  graph.Edge[3][4] = 1;
  graph.Edge[4][0] = 1;
  graph.Edge[4][1] = 1;
  graph.Edge[4][2] = 1;
  graph.Edge[4][3] = 1;

  printGraph(graph);
  /**
        A B C D E
      A 0 1 1 0 0
      B 0 0 1 1 0
      C 0 0 0 1 1
      D 0 0 0 0 1
      E 1 1 1 1 0
   */

  int k = printVertices(graph);
  cout << "Number of K vertices: " << k << endl;

  return 0;
}