// Leveys-ensin-haku (BFS)
// Tama muistiinpano perustuu COMP.CS.300 kurssin luennon "Graafit BFS" luentodioihin

// Askel on yksi siirtyma kaarta pitkin
// Reitti solmusta toiseen koostuu askelista, eri reitit voivat olla eri pituisia
// Solmujen valinen etaisyys δ(v1,v2) kertoo montako askelta minimissaan tarvitaan, 
// etta paastaan solmusta toiseen.

// Suunnatussa graafissa etaisyys solmujen valilla voi vaihdella sen perusteella,
// kummasta solmusta kuljetaan kumpaan.

// Graafissa kaytetaan vareja, joiden avulla voidaan ilmaista kasittelyn tilaa.
// Valkea : alkutila
// Harmaa : loydetty, "kesken"
// Musta : loydetty, loppuun kasitelty

// On tarkeaa yllapitaa aputietorakennetta kesken oleville (harmaille) solmuille, "muistilista"

// Algoritmit liittavat joka solmuun v lisadataa
// v -> d: etaisyys lahtosolmusta soluun
// v -> pi: mista solmusta saavuttiin tahan solmuun
// v -> colour: solmun vari
// v -> Adj: v:n naapurisolmut (mihin solmuihin v:sta lahtee kaaret)

// Leveys-ensin-haku (BFS)
// Etsii kaikki solmut, joihin paasee lahtosolmusta
// Laskee edella mainittujen solmujen etaisyydet lahtosolmusta
// Laskee lyhimman polun lahtosolmusta jokaiseen edellamainittuun solmuun
// Jono (queue) harmaiden solmujen muistilistana
// Lisaksi tarvitaan solmujen lisakentat

// Pseudocode

// breath-first-search(s)  (s on haun lahtosolmu)                  (s on haun lahtosolmu)
// ▷ (Kaikki solmut: colour := white, d := inf, pi := NIL)         
// ▷ (Q on muistilistana toimiva jonotietorakenne)                 
// s -> colour := gray                                             (alkusolmu on kesken)
// s -> d := 0                                                     (etaisyys alkusolmuun 0)
// Push(Q, s)                                                      (alkusolmu muistilistalle)
// while Q =/= empty do                                            (kunnes muistilista on tyhja)
//      u := Pop(Q)                                                (vanhin alkio listasta) 
//      for v in u -> Adj do                                       (kay lapi solmun naapurit)
//          if v-> colour = white then                             (jos uusi solmu... )
//              v-> colour := gray                                 (... se on nyt kesken)
//              v-> d := u-> d + 1                                 (... ja yhta kauempana)
//              v -> pi := u                                       (... ja siihen paasee s:sta)
//              Push(Q, v)                                         (lisataan v listalle)
//      u -> colour := black                                       (s on loppuun kasitelty)

// Properties
// Time Complexity: 𝑂(𝑉+𝐸)
// O(V+E), where 𝑉 is the number of vertices and 
// E is the number of edges. Each vertex is processed once, and each edge is examined once.
// Space Complexity: 𝑂(𝑉)
// O(V), mainly for the queue 𝑄 and the distance/predecessor arrays.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define the structure for a graph
class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line if the graph is directed
    }

    // Perform BFS starting from a source vertex
    void BFS(int s) {
        // Initialize all vertices
        vector<string> colour(V, "white");
        vector<int> d(V, INT_MAX);
        vector<int> pi(V, -1);

        // Initialize the source vertex
        colour[s] = "gray";
        d[s] = 0;

        queue<int> Q;
        Q.push(s);

        // BFS loop
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            // Explore neighbors
            for (int v : adj[u]) {
                if (colour[v] == "white") {
                    colour[v] = "gray";
                    d[v] = d[u] + 1;
                    pi[v] = u;
                    Q.push(v);
                }
            }

            colour[u] = "black";
        }

        // Output results
        cout << "Vertex \t Distance \t Predecessor" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << "\t" << d[i] << "\t";
            if (pi[i] != -1)
                cout << pi[i] << endl;
            else
                cout << "NIL" << endl;
        }
    }
};

int main() {
    // Example usage
    Graph g(6); // Graph with 6 vertices (0 to 5)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Perform BFS starting from vertex 0
    g.BFS(0);

    return 0;
}


// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

// C++ program for BFS of an undirected graph
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS from given source s
void bfs(vector<vector<int>>& adj, int s) 
{
    // Create a queue for BFS
    queue<int> q;  
    
    // Initially mark all the vertices as not visited
    // When we push a vertex into the q, we mark it as 
    // visited
    vector<bool> visited(adj.size(), false);

    // Mark the source node as visited and 
    // enqueue it
    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty()) {
      
        // Dequeue a vertex from queue and print it
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        // Get all adjacent vertices of the dequeued 
        // vertex curr If an adjacent has not been 
        // visited, mark it visited and enqueue it
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adj,
                          int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected Graph
}

int main() 
{
    // Number of vertices in the graph
    int V = 5;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0 : \n";
    bfs(adj, 0);

    return 0;
}