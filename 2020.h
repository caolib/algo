/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-19
 * 定义三元组(a,b,c)（a,b,c均为整数）的距离D=|a-b+|b-c+|c-a|。给定3个非空整数集合S、S和S3，
 * 按升序分别存储在3个数组中。请设计一个尽可能高效的算法，计算并输出所有可能的三元组(a,b,c)（a∈Si，b∈S2，c∈Ss）
 * 中的最小距离。例如S={-1,0,9}，S2={-25,-10,10,11},S={2,9,17,30,41}，则最小距离为2，相应的三元组为(9,10,9)。
 * 要求：找出所有可能的三元组的最小距离
 * @paragraph
 * 基本设计思想：
 * 时间复杂度：
 * 空间复杂度：
 */

#pragma once
#include <iostream>
using namespace std;

// 计算绝对值
int abs(int val) {
  if (val < 0)
    return -val;
  return val;
}
// 找出三个数中的最小值
int minV(int a, int b, int c) {
  int min = a;
  if (b < min)
    min = b;
  if (c < min)
    min = c;
  return min;
}

// 计算三个数的距离
int distance(int a, int b, int c) {
  return abs(a - b) + abs(b - c) + abs(c - a);
}

int findMinDistance(int s1[], int l1, int s2[], int l2, int s3[], int l3) {
  int i = 0, j = 0, k = 0;
  int Dm = __INT_MAX__; // 最小距离
  while (i < l1 && j < l2 && k < l3) {
    int a = s1[i], b = s2[j], c = s3[k];
    int d = distance(a, b, c);
    Dm = d < Dm ? d : Dm;
    int min = minV(a, b, c);
    if (a == min) {
      i++;
    } else if (b == min) {
      j++;
    } else {
      k++;
    }

    printf("%d\t%d\t%d\t距离：%d\n", a, b, c, d);
  }
  return Dm;
}
