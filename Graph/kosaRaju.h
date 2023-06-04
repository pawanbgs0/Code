#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildAdjList(int noNodes, int noEdges);
void DFS(int node, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &res);
void topoDFS(int node, vector<vector<int>> &adjList, vector<int> &visited, stack<int> &st);
vector<vector<int>> reverseAdjList(vector<vector<int>> &adjList);
vector<vector<int>> stronglyConnectedComponents(vector<vector<int>> &adjList);