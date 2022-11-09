// recursion(current, destination)
// if (current == desitnation) count++;
// else for all adj of current:
// recursion(adjacent, destination)


#include <bits/stdc++.h>
using namespace std;

class Graph {
    int m_nodes = 0;
    vector<int> *m_adj;
    void countPathUtil(int curr, int dest, int& count_path, vector<bool> visited);
public:
    Graph(int totalNodes);
    void add_edge(int src, int dest);
    int countPath(int src, int dest, int totalNodes);
};

Graph::Graph(int totalNodes) {
    m_nodes = totalNodes;
    m_adj = new vector<int> [m_nodes];
}

void Graph::add_edge(int src, int dest) {
    m_adj[src].push_back(dest);
}

void Graph::countPathUtil(int curr, int dest, int& count_path, vector<bool> visited) {
    if (curr == dest) {
        count_path++;
    } else {
        for (auto it = m_adj[curr].begin(); it != m_adj[curr].end(); ++it) {
            if (visited[curr] == false) {
                countPathUtil(*it, dest, count_path, visited);
            }
        }
    }
}

int Graph::countPath(int src, int dest, int N) {
    int count_path = 0;
    vector<bool> visited(N);
    countPathUtil(src, dest, count_path, visited);
    return count_path;
}

int main() {
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(2, 1);
      g.add_edge(3, 2);
    // Validate it...
    cout<<g.countPath(0, 4,5);
}