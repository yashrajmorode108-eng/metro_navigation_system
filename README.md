# 🚇 Metro Navigation System

<p align="center">
  <h3 align="center">A Graph-Based Metro Route Navigation System</h3>

  <p align="center">
    Find the fastest route, minimum station path, estimated travel time, total distance, and ticket fare across the Nagpur Metro network using Graph Algorithms.
  </p>
</p>

---

## 📑 Table of Contents

- About the Project
- Features
- Technologies Used
- Project Structure
- Algorithms Used
- How It Works
- Installation
- How to Run
- Sample Menu
- Future Improvements
- Contributing
- Author

---

# 📖 About the Project

The **Metro Navigation System** is a C++ console-based application that simulates the metro network of **Nagpur Metro** using graph data structures.

The system enables users to:

- View all available metro stations
- Find the fastest route between two stations
- Find the route with the minimum number of stations
- Calculate estimated travel time
- Calculate total travelling distance
- Calculate metro ticket fare
- Handle interchange stations intelligently

The metro network is represented as an **undirected weighted graph**, where:

- Stations represent **vertices**
- Tracks represent **edges**
- Edge weights store both **distance** and **travel time**

---

# ✨ Features

✅ Display all Nagpur Metro stations

✅ Find the shortest route based on **minimum travel time**

✅ Find the route with **minimum number of stations**

✅ Automatic fare calculation

✅ Distance calculation

✅ Estimated travel time calculation

✅ Route path visualization

✅ Interchange station detection (Sitabuldi)

✅ Interchange time penalty handling

✅ Input validation for invalid station names

✅ Clean and menu-driven console interface

---

# 🛠️ Technologies Used

- **C++**
- Standard Template Library (STL)
- Graph Data Structure
- Priority Queue
- Queue
- Unordered Map
- Vectors

---

# 📂 Project Structure

```text
metro_navigation_system/
│
├── include/
│   ├── GraphStructures.h
│   └── NagpurMetroSystem.h
│
├── src/
│   ├── NagpurMetroSystem.cpp
│   └── main.cpp
│
└── README.md
```

---

# 🧠 Algorithms Used

## 1. Dijkstra's Algorithm

Used to find the **fastest route** between two metro stations.

### Computes

- Minimum travel time
- Total distance travelled
- Complete route path

The implementation uses:

- Priority Queue (Min Heap)
- Weighted Graph
- Parent Tracking for path reconstruction

---

## 2. Breadth First Search (BFS)

Used to determine the route having the **minimum number of stations** between the source and destination.

This algorithm guarantees the shortest path in terms of station count.

---

## 3. Graph Representation

The metro network is represented using an **Adjacency List**.

Each edge stores:

- Destination station
- Distance
- Travel time

This provides efficient traversal and route computation.

---

# ⚙️ How It Works

1. The metro network is initialized when the application starts.

2. Users select an operation from the main menu.

3. The application accepts source and destination station names.

4. Depending on the selected option:

   - Dijkstra's Algorithm computes the fastest route.
   - BFS computes the minimum station route.

5. The system displays:

- Complete path
- Total stations
- Total distance
- Estimated travel time
- Ticket fare

6. If a route passes through **Sitabuldi**, the system automatically detects an interchange and applies the interchange time penalty when required.

---

# 💻 Installation

## Clone the repository

```bash
git clone https://github.com/yashrajmorode108-eng/metro_navigation_system.git
```

## Navigate to the project

```bash
cd metro_navigation_system
```

---

# ▶️ How to Run

## Using g++

Compile the project

```bash
g++ src/main.cpp src/NagpurMetroSystem.cpp -Iinclude -o metro
```

Run the executable

### Windows

```bash
./metro.exe
```

### Linux / macOS

```bash
./metro
```

---

# 📋 Sample Menu

```text
********************************************
      NAGPUR METRO NAVIGATION SYSTEM
********************************************

1. Display All Metro Stations
2. Find Shortest Path (By Time / Dijkstra)
3. Find Shortest Path (By Number of Stations / BFS)
4. Exit Application
```

---

# 🚀 Future Improvements

- GUI version using Qt
- Interactive metro map
- Live metro timings
- Real-time train tracking
- Multi-city metro support
- Route visualization using graphics
- Database integration
- Mobile application support

---

# 🤝 Contributing

Contributions are always welcome!

If you'd like to improve this project:

1. Fork the repository
2. Create a feature branch

```bash
git checkout -b feature-name
```

3. Commit your changes

```bash
git commit -m "Added new feature"
```

4. Push to your branch

```bash
git push origin feature-name
```

5. Open a Pull Request

---

# 👨‍💻 Author

## **Yashraj Morode**

**GitHub:**  
https://github.com/yashrajmorode108-eng

If you found this project useful, consider giving it a ⭐ on GitHub.

---

<h3 align="center">
⭐ Star this repository if you found it helpful! ⭐
</h3>

<p align="center">
Made with ❤️ by <b>Yashraj Morode</b>
</p>