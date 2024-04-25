/*************************
 * Student Author Name: Khi Kidman
 * Lab Section: 3pm
 * ***********************/

/*
 * The AI Feedback Generator is part of a research study investigating the effectiveness of AI-powered teaching assistance in computer science education. 
 * To receive the AI feedback you must opt-in in the study by submitting the following consent form (The constent form includes your previous participation in using AI-feedback, which allows to use the surveys and submission data for our studies) :
 * https://forms.gle/XZcbWnp9KNzE9NjC7
 *
 * This study involves submitting the survey regarding the effectiveness of AI-feedback.
 * Link to survey:
 * https://forms.gle/cez2pAe2XmhH11MH9
 *
 * To request AI feedback uncomment the following line.
 */

//#define REQUEST_AI_FEEDBACK
//

//To receive AI feedback, DO NOT implement the class methods inside the class definition. 



#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//************************** Node *************************

class Node {
	private:
		int id;
		vector<Node*> neighbors;
	public:
		Node(int id) { this->id = id; }

		vector<Node*> getNeighbors() { return this->neighbors; }

		void setNeighbor(Node* neighbor) { 
			for (Node* n : neighbors) {
				if (n->getId() == neighbor->getId()) {
					return;
				}
			}
			this->neighbors.push_back(neighbor);
		}

		int getId() { return this->id; }

};

//************************** Graph ****************************
class Graph {
	public:
		//add the node with neighborId as the neighbor of nodeId
		void addNeighbor(int nodeId, int neighborId) {
			int maxId = max(nodeId, neighborId);
			while (maxId >= vertices.size()) {
				vertices.push_back(nullptr);
			}

			if (vertices[nodeId] == nullptr) {
				vertices[nodeId] = new Node(nodeId);
			}

			if (vertices[neighborId] == nullptr) {
				vertices[neighborId] = new Node(neighborId);
			}

			vertices[nodeId]->setNeighbor(vertices[neighborId]);
			vertices[neighborId]->setNeighbor(vertices[nodeId]);
		};

		//reads the edge list from file and creates the adjacency list data structure
		void loadGraph(string edgeListFileName) {
			ifstream myInStream;
			myInStream.open(edgeListFileName);

			int i, j;

			while (myInStream >> i >> j) {
				addNeighbor(i, j);
			}
			myInStream.close();
		};
		
		//writes the adjacency list into the file
		void dumpGraph(string adjListFileName) {
			ofstream myOutStream;
			myOutStream.open(adjListFileName);

			for (int i = 0; i < vertices.size(); ++i) {

				if (vertices[i] != nullptr) {
					myOutStream << i << ": ";
					
					vector<Node*> neighbors = vertices[i]->getNeighbors();
					vector<int> ids;
					for (Node* n : neighbors) {
						ids.push_back(n->getId());
					}

					sort(ids.begin(), ids.end());

					for (int id : ids) {
						myOutStream << id << " ";
					}
					myOutStream << endl;
				}
			}

			myOutStream.close();
		};

		//Prints number of nodes, number of edges, and maximum degree on terminal
		void printGraphInfo() {

			int edges = 0;
			int maxDegree = 0;
			
			for (int i = 0; i < vertices.size(); ++i) {
				if (vertices[i] != nullptr) {
					int degree = getNumNeighbors(i);
					edges += degree;
					maxDegree = max(maxDegree, degree);
				}
			}

			cout << "Number of nodes: " << getNumVertices() << endl;
			cout << "Number of edges: " << edges / 2 << endl;
			cout << "Maximum degree: " << maxDegree << endl;
		};

		//returns the number of neighbor (degree) of a node
		int getNumNeighbors(int nodeId) {
			return vertices[nodeId]->getNeighbors().size();
		};

		//returns the number of nodes in the graph
		int getNumVertices() {
			int numVertices = 0;
			for (Node* n : vertices) {
				if (n != nullptr)
					numVertices++;
			}
			return numVertices;
		};

	private:
		vector<Node*> vertices;
		
};


void run(string edgeListFileName, string adjListFileName) {
	Graph graph;
	graph.loadGraph(edgeListFileName);
	graph.dumpGraph(adjListFileName);
	graph.printGraphInfo();
}

//*****************************************************************************


// The main will be removed for testing, do not add any code in the main function 

int main(int argc, char** argv) {
	run(argv[1], argv[2]);
	return 0;	

}

