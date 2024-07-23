/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-23
 * @brief [2022] 判断一棵使用顺序数组保存的二叉树是否为二叉排序树
 * 算法思想：
 * 1.二叉树中(1开始编号)第k结点 =>
 * 左孩子为2k，右孩子为2K+1,保存在数组(0开始)中索引分别为
 * k-1,2(k-1)+1,2(k-1)+2 => x,2*x+1,2*x+2
 * 2.遍历数组，查看每个结点的左右孩子是否满足 左 < 父 < 右
 * 3.循环完成后说明符合条件，返回true
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
#include <iostream>
using namespace std;

bool isBST(int a[], int size) {
  for (int i = 0; i < size; i++) {
    // 如果越界说明为空结点，赋值为-1
    int left = 2 * i + 1 < size ? a[2 * i + 1] : -1;
    int right = 2 * i + 2 < size ? a[2 * i + 2] : -1;
    int parent = a[i];
    // 如果左孩子>=父节点或右孩子<=父节点返回false
    if ((left != -1 && left >= parent) || right != -1 && right <= parent)
      return false;
  }
  return true;
}

int main() {
  int a[] = {40, 24, 60, -1, 30, -1, 80, -1, -1, 27};
  int size = sizeof(a) / sizeof(a[0]);

  string res = isBST(a, size) ? "是二叉排序树" : "不是二叉排序树";
  cout << res << endl;

  return 0;
}