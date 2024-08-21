/**
 * @author libin (1265501579@qq.com)
 * @date 2024-08-21
 * @paragraph
 * 插入排序：遍历数组每个元素，将各个元素插入到有序序列中，初始时一个数就是有序的
 */

void insertSort(int a[], int size) {
  for (int i = 1; i < size; i++) { // 有序区间为 [0,i-1]
    int b = a[i]; // 待插入元素b为有序区间下一个元素
    int j = i - 1;
    // 在有序区间找 <= b 的数
    while (j >= 0 && b < a[j]) {
      a[j + 1] = a[j]; // 后移一位
      j--;
    }
    a[j + 1] = b;
  }
}
