#ifndef _GRAPH_H
#define _GRAPH_H
#include<iostream>


#include <algorithm>
#include <tuple>
#include "disjoint.h"
#include <queue>
using namespace std;
#define Edge tuple<int, int>
#define INF 9999999

class graph{
  public:
    graph();
    ~graph();
    void build(int** arr, int size, vector<string> island);
    void BFS(int x);
    void DFS(int x); 
    void DFS_Helper(int x, bool checked[]);
    void KruskalMST(); 
    void PrimMST();
    void setfree();
    int size;
    int** arr;
    vector<string> islands;
    vector<Edge> tree_BFS;
    vector<Edge> tree_DFS;
    vector<Edge> back_Edges;
    vector<Edge> cross_Edges;
    vector<tuple<int, Edge>> edgesListWith_Weight;
    vector<tuple<int, Edge>> edgesListWithM_Weight;
    vector<tuple<int, Edge>> edgesList_Prim;
};
#endif