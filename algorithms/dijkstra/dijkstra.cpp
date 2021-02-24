#include<iostream>
#include<climits>
#include <bits/stdc++.h>
using namespace std;

vector<int> dist(6, INT_MAX);
vector<bool> visited(6, false);
int graph[6][6] = {
  { 0, 3, 7, 0, 0, 0},
  { 3, 0, 0, 4, 3, 0},
  { 7, 0, 0, 7, 5, 0},
  { 0, 4, 7, 0, 7, 2},
  { 0, 3, 5, 7, 0, 1},
  { 0, 0, 0, 2, 1, 0}};

void print() {
  cout << "Vertex\t\tDistance from source" << endl;
  for (int i = 0; i < 6; i++) cout << i + 1 << "\t\t\t" << dist[i] << endl;
}

int minimumDist() {
  int min = INT_MAX, index;
  for (int i = 0; i < 6; i++) {
    if (!visited[i] && dist[i] <= min) {
      min = dist[i];
      index = i;
    }
  }
  return index;
}

void dijkstra(int src) {
  dist[src] = 0;
  for (int j : dist) {
    int m = minimumDist();
    for (int i = 0; i < 6; i++) {
      if (!graph[m][i] || visited[i]) continue;
      int currPath = dist[m] + graph[m][i];
      if (currPath < dist[i]) dist[i] = currPath;
    }
    visited[m] = true;
  }
}

int main() {
  dijkstra(0);
  print();
  return 0;
}