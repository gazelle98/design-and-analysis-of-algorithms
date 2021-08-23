#include <iostream>
#include <string>
#include <list>

using namespace std;

class Graph {
    int v;
    list<int> *adj1;
    list<int> *adj2;
public:
    int *minDistance;

    Graph(int v);

    void addEdge(int v, int w);

    void BFS(int s);
};

Graph::Graph(int v) {
    this->v = v;
    adj1 = new list<int>[v];
    minDistance = new int[v];
    for (int i = 0; i < v; i++) {
        minDistance[i] = 0;
    }

}

void Graph::addEdge(int v, int w) {
    adj1[v - 1].push_back(w - 1);
    adj1[w - 1].push_back(v - 1);
}


void Graph::BFS(int s) {
    bool *visited = new bool[v];
    int counter = -1;
    for (int i = 0; i < v; i++) {
        visited[i] = false;

    }

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;
    minDistance[s] = counter;

    while (!queue.empty()) {
        s = queue.front();
        queue.pop_front();

        for (i = adj1[s].begin(); i != adj1[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                minDistance[*i] = minDistance[s] + 1;
                queue.push_back(*i);
            }
        }
    }
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int hospitals[k];
    bool isHospital[n];
    int v1, v2;
    Graph graph(n + 1);
    for (int i = 0; i <= n; i++) {
        isHospital[i] = false;
    }
    for (int i = 0; i < k; i++) {
        cin >> hospitals[i];
        isHospital[hospitals[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        graph.addEdge(v1, v2);
    }
    for (int i = 0; i < k; i++) {
        graph.addEdge(n + 1, hospitals[i]);
    }
    graph.BFS(n);
    for (int i = 0; i < n; i++) {

        cout << graph.minDistance[i] << endl;
    }

    return 0;
}