/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-19
 * @brief 输出同时存在于3个有序数组中的所有元素,数组长度均为n
 */
#include "iostream"
using namespace std;

void printSame(int a[], int b[], int c[], int n) {
  int i = 0, j = 0, k = 0;
  while (i < n && j < n && k < n) {
    int va = a[i];
    int vb = b[j];
    int vc = c[k];
    // 找出最大值
    int max = va;
    if (vb > max) {
      max = vb;
    }
    if (vc > max) {
      max = vc;
    }

    if (va == vb && vb == vc) { // 找到相同值，输出后将三个指针同时后移
      cout << va << endl;
      i++;
      j++;
      k++;
      continue;
    }

    if (va < max) { // 没有找到相同值，将数值小的指针向后移
      i++;
    }
    if (vb < max) {
      j++;
    }
    if (vc < max) {
      k++;
    }
  }
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 4, 5, 7};
  int b[] = {1, 2, 3, 4, 5};
  int c[] = {1, 2, 4, 6, 7};

  printSame(a, b, c, 5);
  return 0;
}
