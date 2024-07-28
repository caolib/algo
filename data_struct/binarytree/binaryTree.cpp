/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-24
 * @brief 二叉树的顺序存储，数组从1开始存储结点，保证结点和索引一致
 */

#define MAX 100
typedef struct SqTree {
  int data[MAX];
  int size;
};
