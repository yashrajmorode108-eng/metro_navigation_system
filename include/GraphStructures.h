#ifndef GRAPH_STRUCTURES_H
#define GRAPH_STRUCTURES_H

#include <string>

using namespace std;

struct Edge {
    string dest;
    double distance; 
    double time;     
};

#endif