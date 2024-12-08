#include<iostream>
using namespace std;
#define MAXV 100

typedef struct {
    int numVertices;
    int numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
}MGraph;

int uniquely(MGraph G){
    int v = G.numVertices;
    int e = G.numEdges;
    int index;
    int visit[v];
    for(int i=0;i<v;i++) visit[i] = 0;
    while(e>0){
        int count = 0;
        for(int i=0;i<v;i++){
            if(visit[i]==1) continue;
            int in = 0;
            for(int j=0;j<v;j++)
                if(G.Edge[j][i] != 0) in++;
            if(in == 0){
                count++;
                index = i;
            }
        }
        if(count>1) {
            cout<< "不唯一！";
            return 0;
        }
        if(count==0 && e!=0){
            cout<< "有环！";
            return 0;
        }            
        visit[index] = 1;
        for(int i=0;i<v;i++){
            if(G.Edge[index][i] != 0){
              G.Edge[index][i] = 0;
              e--;
            }             
        }
    }
    return 1;
}


int main() {
    MGraph graph1 = {3, 3, {'A', 'B', 'C'}, {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}}}; // 有环
    MGraph graph2 = {3, 2, {'A', 'B', 'C'}, {{0, 1, 0}, {0, 0, 1}, {0, 0, 0}}}; // 唯一拓扑序列
    MGraph graph3 = {4, 3, {'A', 'B', 'C', 'D'}, {{0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}}}; // 不唯一拓扑序列

    // 测试
    cout << uniquely(graph1) << endl; // 0
    cout << uniquely(graph2) << endl; // 1
    cout << uniquely(graph3) << endl; // 0

    return 0;
}