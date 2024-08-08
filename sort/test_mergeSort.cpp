#include "./mergeSort.h"
#include <iostream>

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int a[] = {1, 3, 5, 7, 9};
  int n = sizeof(a) / sizeof(a[0]);

  int b[] = {2, 4, 6, 8, 10};
  int m = sizeof(b) / sizeof(b[0]);

  int c[n + m];

  merge(a, n, b, m, c);

  std::cout << "Merged array: ";
  printArray(c, n + m);

  return 0;
}