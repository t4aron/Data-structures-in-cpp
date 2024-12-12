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

enum Colour {WHITE, GRAY, BLACK};

struct Node
{
    // All the data stored in the node
    int id;
    std::string name;

    int d; // Distance
    Node* path_back; // pi
    Colour colour;

    std::vector<Node*> to_neighbours;

};

// Tai isommilla graafeilla osa hakuun liittyvista piirteista voidaan tallentaa erilliseen structiin

enum Colour {WHITE, GRAY, BLACK};

struct SearchInfo
{
    int d; // distance
    Node* path_back; // pi
    Colour colour; 
};

struct Node
{
    // All the data stored in the node
    int id;
    std::string name;

    SearchInfo* search_info; // must be created!

    std::vector<Node*> to_neighbours;

};