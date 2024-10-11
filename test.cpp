#include <unordered_map>
#include <vector>
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
