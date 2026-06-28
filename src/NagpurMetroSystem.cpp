#include "NagpurMetroSystem.h"
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std; // Applied globally for this implementation module

NagpurMetroSystem::NagpurMetroSystem() {
    initializeNetwork();
}

void NagpurMetroSystem::addStation(const string& name, const string& line) {
    stationLines[name] = line;
}

void NagpurMetroSystem::addTrack(const string& s1, const string& s2, double distance, double time) {
    graph[s1].push_back({s2, distance, time});
    graph[s2].push_back({s1, distance, time});
}

void NagpurMetroSystem::initializeNetwork() {
    // --- ORANGE LINE ---
    addStation("Automotive Square", "Orange");
    addStation("Indora Square", "Orange");
    addStation("Kadbi Square", "Orange");
    addStation("GaddiGodam Square", "Orange");
    addStation("Zero Mile Freedom Park", "Orange");
    addStation("Sitabuldi", "Interchange"); 
    addStation("Congress Nagar", "Orange");
    addStation("Rahate Colony", "Orange");
    addStation("Ajni Square", "Orange");
    addStation("Chhatrapati Square", "Orange");
    addStation("Jaiprakash Nagar", "Orange");
    addStation("Ujjwal Nagar", "Orange");
    addStation("Airport", "Orange");
    addStation("Khapri", "Orange");

    addTrack("Automotive Square", "Indora Square", 1.4, 2.5);
    addTrack("Indora Square", "Kadbi Square", 1.1, 2.0);
    addTrack("Kadbi Square", "GaddiGodam Square", 1.2, 2.0);
    addTrack("GaddiGodam Square", "Zero Mile Freedom Park", 1.0, 1.8);
    addTrack("Zero Mile Freedom Park", "Sitabuldi", 0.9, 1.5);
    addTrack("Sitabuldi", "Congress Nagar", 1.2, 2.0);
    addTrack("Congress Nagar", "Rahate Colony", 0.9, 1.5);
    addTrack("Rahate Colony", "Ajni Square", 1.1, 2.0);
    addTrack("Ajni Square", "Chhatrapati Square", 1.3, 2.2);
    addTrack("Chhatrapati Square", "Jaiprakash Nagar", 0.9, 1.5);
    addTrack("Jaiprakash Nagar", "Ujjwal Nagar", 1.0, 1.8);
    addTrack("Ujjwal Nagar", "Airport", 1.2, 2.0);
    addTrack("Airport", "Khapri", 3.2, 5.0);

    // --- AQUA LINE ---
    addStation("Lokmanya Nagar", "Aqua");
    addStation("Bansi Nagar", "Aqua");
    addStation("Vasudev Nagar", "Aqua");
    addStation("Rachana Ring Road", "Aqua");
    addStation("Subhash Nagar", "Aqua");
    addStation("Dharampeth College", "Aqua");
    addStation("Jhansi Rani Square", "Aqua");
    addStation("Cotton Market", "Aqua");
    addStation("Nagpur Railway Station", "Aqua");
    addStation("Dosar Vaisya Square", "Aqua");
    addStation("Agrasen Square", "Aqua");
    addStation("Chitar Oli Square", "Aqua");
    addStation("Telephone Exchange", "Aqua");
    addStation("Ambedkar Square", "Aqua");
    addStation("Prajapati Nagar", "Aqua");

    addTrack("Lokmanya Nagar", "Bansi Nagar", 1.2, 2.0);
    addTrack("Bansi Nagar", "Vasudev Nagar", 1.0, 1.8);
    addTrack("Vasudev Nagar", "Rachana Ring Road", 1.1, 2.0);
    addTrack("Rachana Ring Road", "Subhash Nagar", 0.9, 1.5);
    addTrack("Subhash Nagar", "Dharampeth College", 1.2, 2.1);
    addTrack("Dharampeth College", "Jhansi Rani Square", 1.4, 2.4);
    addTrack("Jhansi Rani Square", "Sitabuldi", 0.8, 1.5);
    addTrack("Sitabuldi", "Cotton Market", 1.0, 1.8);
    addTrack("Cotton Market", "Nagpur Railway Station", 0.9, 1.5);
    addTrack("Nagpur Railway Station", "Dosar Vaisya Square", 1.1, 2.0);
    addTrack("Dosar Vaisya Square", "Agrasen Square", 1.0, 1.8);
    addTrack("Agrasen Square", "Chitar Oli Square", 0.8, 1.5);
    addTrack("Chitar Oli Square", "Telephone Exchange", 1.1, 2.0);
    addTrack("Telephone Exchange", "Ambedkar Square", 1.3, 2.3);
    addTrack("Ambedkar Square", "Prajapati Nagar", 1.2, 2.1);
}

int NagpurMetroSystem::calculateFare(double distance) {
    if (distance <= 2.0) return 10;
    if (distance <= 6.0) return 20;
    if (distance <= 12.0) return 30;
    return 40;
}

void NagpurMetroSystem::displayStations() {
    cout << "\n============================================\n";
    cout << "         NAGPUR METRO STATIONS LIST\n";
    cout << "============================================\n";
    cout << "[ORANGE LINE]:\n";
    for(const auto& pair : stationLines) {
        if(pair.second == "Orange" || pair.second == "Interchange") cout << "  • " << pair.first << "\n";
    }
    cout << "\n[AQUA LINE]:\n";
    for(const auto& pair : stationLines) {
        if(pair.second == "Aqua" || pair.second == "Interchange") cout << "  • " << pair.first << "\n";
    }
    cout << "============================================\n";
}

void NagpurMetroSystem::findShortestRoute(const string& src, const string& dest) {
    if (graph.find(src) == graph.end() || graph.find(dest) == graph.end()) {
        cout << "\nError: Invalid station name entered. Please check spelling.\n";
        return;
    }

    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;
    unordered_map<string, double> minTime;
    unordered_map<string, double> distTo;
    unordered_map<string, string> parent;

    for (const auto& pair : graph) {
        minTime[pair.first] = INT_MAX;
        distTo[pair.first] = INT_MAX;
    }

    pq.push({0.0, src});
    minTime[src] = 0.0;
    distTo[src] = 0.0;

    while (!pq.empty()) {
        string current = pq.top().second;
        double currentTime = pq.top().first;
        pq.pop();

        if (current == dest) break;
        if (currentTime > minTime[current]) continue;

        for (const auto& edge : graph[current]) {
            double travelTime = edge.time;
            
            if (current == "Sitabuldi" && parent.find(current) != parent.end()) {
                string prevStation = parent[current];
                if (stationLines[prevStation] != stationLines[edge.dest] && 
                    stationLines[prevStation] != "Interchange" && 
                    stationLines[edge.dest] != "Interchange") {
                    travelTime += 4.0; // 4 mins platform interchange penalty
                }
            }

            if (minTime[current] + travelTime < minTime[edge.dest]) {
                minTime[edge.dest] = minTime[current] + travelTime;
                distTo[edge.dest] = distTo[current] + edge.distance;
                parent[edge.dest] = current;
                pq.push({minTime[edge.dest], edge.dest});
            }
        }
    }

    displayRouteResults(src, dest, parent, minTime[dest], distTo[dest]);
}

void NagpurMetroSystem::displayRouteResults(const string& src, const string& dest, 
                                             unordered_map<string, string>& parent, 
                                             double totalTime, double totalDist) {
    if (totalTime == INT_MAX) {
        cout << "\nNo route found between selected stations.\n";
        return;
    }

    vector<string> path;
    string curr = dest;
    while (curr != src) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());

    cout << "\n============================================\n";
    cout << "             ROUTE INFORMATION              \n";
    cout << "============================================\n";
    cout << "▶ Source:      " << src << "\n";
    cout << "▶ Destination: " << dest << "\n";
    cout << "--------------------------------------------\n";
    cout << "Total Stations: " << path.size() << "\n";
    cout << "Total Distance: " << fixed << setprecision(2) << totalDist << " km\n";
    cout << "Estimated Time: " << fixed << setprecision(1) << totalTime << " mins\n";
    cout << "Ticket Fare:    ₹" << calculateFare(totalDist) << "\n";
    cout << "--------------------------------------------\n";
    cout << "ROUTE PATH:\n";
    
    for (size_t i = 0; i < path.size(); ++i) {
        cout << "  " << path[i];
        if (i < path.size() - 1) {
            if (path[i] == "Sitabuldi" && i > 0 && i < path.size() - 1) {
                if (stationLines[path[i-1]] != stationLines[path[i+1]]) {
                    cout << " \n  [🔄 INTERCHANGE - Switch Platforms] \n";
                }
            }
            cout << "  ➔  \n";
        }
    }
    cout << "\n============================================\n";
}
void NagpurMetroSystem::findMinStationsRoute(const string& src, const string& dest) {
    if (graph.find(src) == graph.end() || graph.find(dest) == graph.end()) {
        cout << "\nError: Invalid station name entered. Please check spelling.\n";
        return;
    }

    queue<string> q;
    unordered_map<string, bool> visited;
    unordered_map<string, string> parent;
    
    // Auxiliary maps to track distance/time cumulative values along the BFS path
    unordered_map<string, double> distTo;
    unordered_map<string, double> timeTo;

    for (const auto& pair : graph) {
        distTo[pair.first] = 0.0;
        timeTo[pair.first] = 0.0;
        visited[pair.first] = false;
    }

    q.push(src);
    visited[src] = true;

    bool found = false;
    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == dest) {
            found = true;
            break;
        }

        for (const auto& edge : graph[current]) {
            if (!visited[edge.dest]) {
                visited[edge.dest] = true;
                parent[edge.dest] = current;
                distTo[edge.dest] = distTo[current] + edge.distance;
                
                double travelTime = edge.time;
                // Apply line interchange penalty if passing through Sitabuldi
                if (current == "Sitabuldi" && parent.find(current) != parent.end()) {
                    string prevStation = parent[current];
                    if (stationLines[prevStation] != stationLines[edge.dest] && 
                        stationLines[prevStation] != "Interchange" && 
                        stationLines[edge.dest] != "Interchange") {
                        travelTime += 4.0;
                    }
                }
                timeTo[edge.dest] = timeTo[current] + travelTime;
                
                q.push(edge.dest);
            }
        }
    }

    if (found) {
        displayRouteResults(src, dest, parent, timeTo[dest], distTo[dest]);
    } else {
        cout << "\nNo route found between selected stations.\n";
    }
}