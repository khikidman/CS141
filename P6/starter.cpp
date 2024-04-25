#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Node {
public:
    list<int> neighbors; // Linked list to store neighbors

    // Adds a neighbor to the list maintaining sorted order
    void addNeighbor(int neighborId) {
        if (find(neighbors.begin(), neighbors.end(), neighborId) == neighbors.end()) {
            neighbors.push_back(neighborId);
            neighbors.sort();
        }
    }
};

class Graph {
private:
    vector<Node*> vertices;

public:
    // Add neighbor, ensuring no duplicate edges and managing both directions
    void addNeighbor(int nodeId, int neighborId) {
        while (nodeId >= vertices.size() || neighborId >= vertices.size()) {
            vertices.push_back(nullptr);
        }

        if (vertices[nodeId] == nullptr) {
            vertices[nodeId] = new Node();
        }
        if (vertices[neighborId] == nullptr) {
            vertices[neighborId] = new Node();
        }

        vertices[nodeId]->addNeighbor(neighborId);
        vertices[neighborId]->addNeighbor(nodeId);
    }

    // Load graph from file
    void loadGraph(string edgeListFileName) {
        ifstream infile(edgeListFileName);
        int u, v;
        while (infile >> u >> v) {
            addNeighbor(u, v);
        }
    }

    // Dump graph to file
    void dumpGraph(string adjListFileName) {
        ofstream outfile(adjListFileName);
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] != nullptr) {
                outfile << i << ": ";
                for (auto it = vertices[i]->neighbors.begin(); it != vertices[i]->neighbors.end(); ++it) {
                    outfile << *it << (next(it) != vertices[i]->neighbors.end() ? " " : "");
                }
                outfile << endl;
            }
        }
        outfile.close();
    }

    // Print graph info
    void printGraphInfo() {
        int numEdges = 0, maxDegree = 0;
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] != nullptr) {
                int degree = vertices[i]->neighbors.size();
                numEdges += degree;
                maxDegree = max(maxDegree, degree);
            }
        }
        cout << "Number of vertices: " << getNumVertices() << endl;
        cout << "Number of edges: " << numEdges / 2 << endl; // Each edge counted twice
        cout << "Maximum degree: " << maxDegree << endl;
    }

    // Get the number of vertices
    int getNumVertices() {
        int count = 0;
        for (auto v : vertices) {
            if (v != nullptr) count++;
        }
        return count;
    }
};

void run(string edgeListFileName, string adjListFileName) {
    Graph g;
    g.loadGraph(edgeListFileName);
    g.dumpGraph(adjListFileName);
    g.printGraphInfo();
}

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " edgeListFileName adjListFileName" << endl;
        return 1;
    }
    run(argv[1], argv[2]);
    return 0;    
}
