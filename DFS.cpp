// Syvyys-ensin-haku (DFS)
// Tama muistiinpano perustuu COMP.CS.300 kurssin luennon "Graafit DFS" luentodioihin

// Verrattuna leveys-ensin-hakuun (BFS) syvyys-ensin-haku etsii myos kaikki solmut,
// joihin paasee annetusta lahtosolmusta.

// Laskee jonkin polun lahtosolmusta joka em. solmuun.

// Selvittaa loytyyko poluista silmuikoita.

// Pino (stack) harmaiden solmujen muistilistana

// Muistinkulutus usein BFS:saa pienempi

// Pseudocode for DFS

// Depth-first-search(s)
// ▷ (Kaikki solmut: colour := white)         
// ▷ (S on muistilistana toimiva pinotietorakenne)       
// Push(S, s)                                               (alkusolmu muistilistalle valkoisena)
// while S =/= empty do                                     (kunnes muistilista on tyhja)
//      u := Pop(S)                                         (uusin alkio pinosta)
//      if u -> colour = white then                         (jos kyse on uudesta alkiosta)
//          u -> colour = gray                              (niin se on nyt kesken)
//          Push(S, u)                                      (... ja laitetaan uudelleen listalle)
//          for v in u -> Adj do                            (kay lapi solmun naapurit)
//              if v -> colour = white then                 (jos uusi solmu...)
//                  Push(S, v)                              (lisataan pinoon)
//              else if v -> colour = gray then             (paastiin takaisin, simukka!)
//                  ▷ (kasittele silmukka)
//      else
//          u -> colour := black                            (solmu tuli uudelleen, nyt valmis)

// Rekursiivinen (DFS)
// Aluksi merkitaan kaikki solmut: colour := white
// Muistilista pinona toimii funktioiden kutsupino

// Depth-first-search(s)                                    (s on haun lahtosolmu)
// s -> colour := gray
// for v in s -> Adj do                                     (kay lapi solmun naapurit)
//      if v -> colour = white then                         (jos uusi solmu... )
//              Depth-first-search(v)                       (... kay se lapi rekursiivisesti)
//      else if v -> colour = gray then                     (paastiin takaisin, silmukka!)
//              ▷ (kasittele silmukka)
// s -> colour := black                                     (aivan lopuksi vari mustaksi)

// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

#include <iostream>
#include <vector>
using namespace std;

// Recursive function for DFS traversal
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
  
    visited[s] = true;

    // Print the current vertex
    cout << s << " ";

    // Recursively visit all adjacent vertices
    // that are not visited yet
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}

// Main DFS function that initializes the visited array
// and call DFSRec
void DFS(vector<vector<int>> &adj, int s){
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
}

// To add an edge in an undirected graph
void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t); 
    adj[t].push_back(s); 
}

int main(){
    int V = 5; 
    vector<vector<int>> adj(V);
  
    // Add edges
    vector<vector<int>> edges={{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    int s = 1; // Starting vertex for DFS
    cout << "DFS from source: " << s << endl;
    DFS(adj, s); // Perform DFS starting from the source vertex

    return 0;
}