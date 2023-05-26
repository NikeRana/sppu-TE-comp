#include <bits/stdc++.h> 
using namespace std;

class Graph
{
    unordered_map<int , set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
public:
    void prepareAdjList(int u , int v)
    {   
           adjList[u].insert(v);
           adjList[v].insert(u);   
    }

    void bfs(int node){

    queue<int> q;
    q.push(node);
    visited[node] = 1;
     
     while(!q.empty()){
         int frontNode = q.front();
         cout<<q.front()<<", ";
         q.pop();

         // store frontNode into ans
         ans.push_back(frontNode);

         //traverse all neighbours of frntNOde
         for(auto i: adjList[frontNode]) {
             if(!visited[i]) {
                 q.push(i);
                 visited[i] = 1;
             } 
         }
     }
}    


};

int main() {
    Graph obj = Graph();
    obj.prepareAdjList(0,1);
    obj.prepareAdjList(0,3);
    obj.prepareAdjList(1,2);
    obj.prepareAdjList(2,3);

    obj.bfs(0);
}