// Jokaisessa kaaressa on paino/kustannus
// Algoritmit etsivat halvimpia/keveimpia polkuja solmujen valilla
// BFS ei toimi koska kaaren hinta on aina 1
// Kaaret voi sisaltaa myos muuta dataa, esim tien nopeusrajoitus
// Usein paino tai kustannus rajoitetaan positiiviseksi.

// Edge data can be shared between directions

#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int cost;
    string name;
    Hugedata data;
};

struct Node
{
    // All the data storein in the node
    int id;
    std::string name;
    // ...

    // ... map, not set like before!
    std::unordered_map<Node*>,std::shared_ptr<Edge>> 
    to_neighbours;
};