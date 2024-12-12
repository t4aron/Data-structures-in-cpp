// Pseudocode

// Djikstra(s)                                                        (s on haun lahtosolmu)
// ▷ (Kaikki solmut: colour := white, d := inf, pi := NIL)         
// ▷ (Q on muistilistana toimiva prioriteettijono-tietorakenne)     
// s -> colour := gray                                                (alkusolmu on kesken)
// s -> d := 0                                                        (etaisyys alkusolmuun 0)
// Push(Q, s, 0)                                                         (alkusolmu muistilistalle)
// while Q =/= empty do                                               (kunnes muistilista on tyhja)
//      u := Extract-min(Q)                                           (halvin alkio listasta)
//      for v in u -> Adj do                                          (kay lapi solmun naapurit)
//          Relax(u, v)                                               (laske tai korjaa hinta)
//          if v -> colour = white then                               (jos uusi solmu... )
//              v -> colour := gray                                   (... se on nyt kesken)
//              Push(Q, v, v -> d)                                       (... ja laitetaan se jonoon)
//          else
//              ▷ Jos hinta pieni korjaa prioriteetti Q:ssa!
//      u -> colour := black                                          (nyt s on loppuun kasitelty)

// Relax(u, v)                                                        (laske/korjaa hinta u:n kautta solmuun v)
// if v -> d > u -> d + cost(u, v) then                               (jos hinta v:hen u:n kautta on entista halvempi...)
//      v -> d > u -> d = cost(u, v)                                  (... paivita hinta)
//      v -> pi := u                                                  (... ja se, etta tultiin u:sta)

// Djikstran toteutus edellyttaa minimi-prioriteettijonon
// STL:ssa on valmiiksi std::priority_queue maksimiprioriteettijono
// Tallennetaan prioriteetiksi -d tai mukautetaan prioriteettijonoa

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define the graph as an adjacency list
typedef pair<int, int> pii; // {weight, node}

void dijkstra(int start, const vector<vector<pii>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // Distance to each node, initialized to "infinity"
    priority_queue<pii> pq;       // Priority queue to store { -distance, node }

    // Start with the source node
    dist[start] = 0;
    pq.push({0, start}); // Push { -distance, node }

    while (!pq.empty()) {
        auto [neg_d, u] = pq.top();
        pq.pop();
        int d = -neg_d; // Convert back to positive distance

        // If this distance is not the current shortest distance, skip it
        if (d > dist[u]) continue;

        // Traverse all neighbors
        for (auto [weight, v] : graph[u]) {
            int new_dist = d + weight;

            // If a shorter path to v is found
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({-new_dist, v}); // Push with negative distance for min-heap
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << '\n';
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pii>> graph(n);

    // Add edges: {weight, destination}
    graph[0].push_back({1, 1});
    graph[0].push_back({4, 2});
    graph[1].push_back({2, 2});
    graph[1].push_back({6, 3});
    graph[2].push_back({3, 3});
    graph[3].push_back({1, 4});

    int start = 0; // Source node
    dijkstra(start, graph);

    return 0;
}

// Lisaksi prioriteettia on pystyttava paivittamaan
// std::priority_queue ei tarjoa tata, lisaa solmu aina uudelleen
// tai kayta jotain muuta prioriteettijonoa (esim. std::set<std::pair<int, Node*>>)