#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void dfs(int v, bool visited[]);

    public:
        Graph(int V);
        void addEdge(int v, int w);
        void init_dfs(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::dfs(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfs(*i, visited);
}

void Graph::init_dfs(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    dfs(v, visited);
}

int main()
{
    int num_of_vertices = 5;
    Graph g(num_of_vertices);

    // Add both directions to simulate undirected graph
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 4);
    g.addEdge(4, 1);

    for (int start_vertex = 0; start_vertex < num_of_vertices; ++start_vertex)
    {
        cout << "DFS starting from vertex " << start_vertex << ": ";
        g.init_dfs(start_vertex);
        cout << endl;
    }

    return 0;
}
