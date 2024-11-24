#include<iostream>

using namespace std;

int find_min_number(int a[],int size){
    for(int i = 0;i < size - 1;i++)
        if(a[i+1] < a[i]) return a[i+1];
    return a[0];
}

int main(){

    int a[] = {4,5,6,7,8,9,1,2,3};

    cout<<find_min_number(a,9)<<endl;

    return 0;
}