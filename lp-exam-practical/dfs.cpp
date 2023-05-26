#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Graph 
{
 unordered_map<int , list<int>> adjList;
 unordered_map<int , bool> visited;
 vector<vector<int>> ans;

public:
    void prepareAdjList(int u , int v)
    {   
           adjList[u].push_back(v);
           adjList[v].push_back(u);   
    }

    void dfsutil(int node ,unordered_map<int , bool> &visited, unordered_map<int , list<int>> &adjList, vector <int> &component)
    {
        component.push_back(node);
        cout<< node << " ";
        visited[node] = true;

        for(auto i:adjList[node]) {
            if(!visited[i]) {
                dfsutil(i,visited,adjList,component);
            }
        }
    }

    void dfs(int node){
        // for(int i=0;i<adjList.size();i++){
            vector <int> component;
            dfsutil(node,visited,adjList,component);
            // ans.push_back(component);
        // }
    }


};

int main() {
    Graph obj = Graph();
    obj.prepareAdjList(0,1);
    obj.prepareAdjList(0,2);
    obj.prepareAdjList(1,3);
    obj.prepareAdjList(1,4);
    obj.prepareAdjList(2,5);
    obj.prepareAdjList(2,6);

    obj.dfs(0);
}