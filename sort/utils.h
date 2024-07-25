#pragma once
#include <random>
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void shuffleArray(int arr[], int size) {
  std::random_device rd;
  std::mt19937 gen(rd());

  for (int i = size - 1; i > 0; --i) {
    std::uniform_int_distribution<int> dis(0, i);
    int j = dis(gen);
    swap(arr[i], arr[j]);
  }
}