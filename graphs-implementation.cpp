// Graphs are not included in c++ headers like some other data structures
// Graphs are reliant on existing structures so it's better that the developer creates their own
// graphs as they can tailor it to their own needs.

#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

std::unordered_map<int, Node> nodes;

struct Node
{
    // All the data stored in the node
    int id;
    std::string name;
    // ...

    std::vector<Node*> to_neighbours;
};

// Kuten huomataan, graafin toteutus on identtinen puun kanssa, mika ei ole yllattavaa,
// puu on kuitenkin vain graafi, tietyilla rajoituksilla.