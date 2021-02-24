#include <bits/stdc++.h>
using namespace std;

#define V 6
#define INF 99999

int dist[V][V];
int graph[V][V] = {
    { INF, 3, 7, INF, INF, INF},
    { 3, INF, INF, 4, 3, INF},
    { 7, INF, INF, 7, 5, INF},
    { INF, 4, 7, INF, 7, 2},
    { INF, 3, 5, 7, INF, 1},
    { INF, INF, INF, 2, 1, INF}};

void floydWarshall ()
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                // if (dist[i][k] + dist[k][j] < dist[i][j])
                    // dist[i][j] = dist[i][k] + dist[k][j];
}

void printSolution() {
    cout << "The following matrix shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<"     ";
            else
                cout<<dist[i][j]<<"     ";
        }
        cout<<endl;
    }
}

int main() {
    floydWarshall();
    printSolution();
    return 0;
}