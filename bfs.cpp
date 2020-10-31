#include <iostream>
#include<queue>
using namespace std;

void breadthfirstsearch(int** edges,int n,int se, bool *visited){
    queue<int> pendingVertices;
    int sv =0;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(pendingVertices.size()!=0){
        int temp = pendingVertices.front();
        pendingVertices.pop();
        cout<<temp<<" ";
        for(int i=0;i<n;i++){
            if(i==temp)
                continue;
            if(edges[temp][i]==1&&!visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    int **edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i] = new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    breadthfirstsearch(edges,V,0,visited);

  return 0;
}
