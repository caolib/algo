#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int findDuplicate(vector<int>& nums){
    unordered_map<int,bool>map;
    for (int i : nums){
        if(map[i])
            return i;
        map[i] = true;
    }
    return 0;
}

int main(){
    bool b[10000];

    for(int i = 0;i<10000;i++)
        cout<<b[i]<<endl;

    return 0;
}