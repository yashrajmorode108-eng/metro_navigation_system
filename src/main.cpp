#include <iostream>
#include "NagpurMetroSystem.h"

using namespace std;

int main() {
    NagpurMetroSystem metro;
    int choice;
    string src, dest;

    while (true) {
        cout << "\n********************************************\n";
        cout << "      NAGPUR METRO NAVIGATION SYSTEM        \n";
        cout << "********************************************\n";
        cout << "1. Display All Metro Stations\n";
        cout << "2. Find Shortest Path (By Time / Dijkstra)\n";
        cout << "3. Find Shortest Path (By Number of Stations / BFS)\n";
        cout << "4. Exit Application\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid Input. Exiting program.\n";
            break;
        }
        cin.ignore(); 

        if (choice == 4) {
            cout << "\nThank you for using Nagpur Metro Planner!\n";
            break;
        }

        switch (choice) {
            case 1:
                metro.displayStations();
                break;
            case 2:
                cout << "\n[Dijkstra Optimization Mode]";
                cout << "\nEnter Source Station Name: ";
                getline(cin, src);
                cout << "Enter Destination Station Name: ";
                getline(cin, dest);
                metro.findShortestRoute(src, dest);
                break;
            case 3:
                cout << "\n[BFS Fewer-Stops Mode]";
                cout << "\nEnter Source Station Name: ";
                getline(cin, src);
                cout << "Enter Destination Station Name: ";
                getline(cin, dest);
                metro.findMinStationsRoute(src, dest);
                break;
            default:
                cout << "\nInvalid Choice! Please pick an option from 1-4.\n";
        }
    }
    return 0;
}