#ifndef NAGPUR_METRO_SYSTEM_H
#define NAGPUR_METRO_SYSTEM_H

#include <string>
#include <vector>
#include <unordered_map>
#include "GraphStructures.h"

using namespace std;

class NagpurMetroSystem {
private:
    unordered_map<string, vector<Edge>> graph;
    unordered_map<string, string> stationLines;

    void initializeNetwork();
    int calculateFare(double distance);
    void displayRouteResults(const string& src, const string& dest, 
                             unordered_map<string, string>& parent, 
                             double totalTime, double totalDist);

public:
    NagpurMetroSystem();
    void addStation(const string& name, const string& line);
    void addTrack(const string& s1, const string& s2, double distance, double time);
    void displayStations();
    void findShortestRoute(const string& src, const string& dest);
    void findMinStationsRoute(const string& src, const string& dest);
};

#endif