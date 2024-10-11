/**
 * @author clb (1265501579@qq.com)
 * @date 2024-07-24
 * @brief 将n个正整数划分为n1和n2个数组成的两个集合，S1和S2是两个集合的元素之和
 * 要求两个集合数量相差最小，总和S差值最大
 * @paragraph
 * 算法思想：排序 => 分成两半
 */
#include "func.h"
#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int a[], int low, int high){
    if (low >= high)
        return;
    int i = low, j = high; // 左右指针
    while (i < j){
        while (i < j && a[j] >= a[low])
            j--;
        while (i < j && a[i] <= a[low])
            i++;
        swap(a[i], a[j]);
    }
    swap(a[low], a[i]);
    quickSort(a, low, i - 1);
    quickSort(a, i + 1, high);
}

int depart(int a[], int size){
    quickSort(a, 0, size - 1);
    print(a, size);
    int mid = size % 2 == 0 ? (size - 1) / 2 : (size - 1) / 2 - 1;
    int s1 = 0, s2 = 0;
    for (int i = 0; i <= mid; i++)
        s1 += a[i];
    for (int j = mid + 1; j < size; j++)
        s2 += a[j];

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    return s2 - s1;
}

int main(){
    // int a[] = {2, 1, 4, 3, 5, 6};
    // int n = sizeof(a) / sizeof(a[0]);

    // cout << depart(a, n) << endl;

    double a = 1;
    cout << a << endl;
    system("pause");
    return 0;
}
