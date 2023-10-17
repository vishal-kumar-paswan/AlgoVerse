/*
Approach:

1. Start by initializing data structures:
- Initialize a priority queue to prioritize nodes based on their distances.
- Initialize a distances array to keep track of the shortest distances from the starting node to each node in the graph.

2. Then, perform Dijkstra's algorithm:
- Begin with the starting node and set its distance to 0.
- Add the starting node to the priority queue with a distance of 0.
- While the priority queue is not empty:
  - Pop a node from the priority queue.
  - For each neighbor of the current node, update its distance if a shorter path is found and add it to the priority queue.
- Repeat until all reachable nodes have been visited.

3. Finally, output the shortest distances:
- Print the shortest distances from the starting node to all other nodes in the graph.

Time Complexity: O(V log V + E log V), where V is the number of vertices (nodes) and E is the number of edges in the graph. The dominant factor is the operations involving the priority queue, which takes O(log V) time for each of the V vertices and O(log V) time for each of the E edges (in the worst case).

Space Complexity: O(V) for the distances array and O(V) for the priority queue. Therefore, the overall space complexity is O(V).
*/
// Dijkstra's Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

void dijkstra(std::vector<std::vector<Edge>>& graph, int start, std::vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF);
    distances[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distances[u])
            continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int n = 6; // Number of vertices
    std::vector<std::vector<Edge>> graph(n);
    
    // Add edges and weights to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({5, 1});
    graph[4].push_back({5, 5});

    int start_node = 0;
    std::vector<int> distances;
    dijkstra(graph, start_node, distances);

    std::cout << "Shortest distances from node " << start_node << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "To node " << i << ": " << distances[i] << '\n';
    }

    return 0;
}
