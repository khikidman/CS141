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

using namespace std;

//************************** Node *************************

class Node {
	private:
		int value;
		int id;
		vector<Node*> neighbors;
	public:
		vector<Node*> getNeighbors() {
			return this->neighbors;
		}

		void setNeighbor(Node* neighbor) {
			this->neighbors.push_back(neighbor);
		}

		int getValue() {
			return this->value;
		}

		void setValue(int value) {
			this->value = value;
		}

		int getId() {
			return this->id;
		}

		void setId(int id) {
			this->id = id;
		}


};

//************************** Graph ****************************
class Graph {
	public:
		//add the node with neighborId as the neighbor of nodeId
		void addNeighbor(int nodeId, int neighborId) {
			this->vertices.at(nodeId)->setNeighbor(vertices.at(neighborId));
			this->vertices.at(neighborId)->setNeighbor(vertices.at(nodeId));
		};

		//reads the edge list from file and creates the adjacency list data structure
		void loadGraph(string edgeListFileName) {
			
		};
		
		//writes the adjacency list into the file
		void dumpGraph(string adjListFileName) {
			ofstream myOutStream;
			myOutStream.open(adjListFileName);

			for (int i = 0; i < vertices.size(); ++i) {
				for (int j = 0; j < vertices.at(i)->getNeighbors().size(); ++j) {
					if (vertices.at(i)->getNeighbors().at(j)->getId() > i) {
						myOutStream << vertices.at(i)->getId() << " " << vertices.at(i)->getNeighbors().at(j)->getId();
					}
				}
			}

			myOutStream.close();
		};

		//Prints number of nodes, number of edges, and maximum degree on terminal
		void printGraphInfo() {
			cout << "Number of nodes: " << this->vertices.size() << endl;
			
			int edges = 0;
			int max_degree = 0;
			for (int i = 0; i < vertices.size(); ++i) {

				for (int j = 0; j < vertices.at(i)->getNeighbors().size(); ++i) {
					if (vertices.at(i)->getNeighbors().at(j)->getId() > i) {
						edges += 1;
					}
				}

				if (vertices.at(i)->getNeighbors().size() > max_degree) {
					max_degree = vertices.at(i)->getNeighbors().size();
				}

			}

			cout << "Number of edges: " << edges << endl;
			cout << "Maximum degree: " << max_degree << endl;
		};

		//returns the number of neighbor (degree) of a node
		int getNumNeighbors(int nodeId) {
			return vertices.at(nodeId)->getNeighbors().size();
		};

		//returns the number of nodes in the graph
		int getNumVertices() {
			return this->vertices.size();
		};

	private:
		vector<Node*> vertices;
		
};


void run(string edgeListFileName, string adjListFileName) {
}

//*****************************************************************************


// The main will be removed for testing, do not add any code in the main function 

int main(int argc, char** argv) {
	run(argv[1], argv[2]);
	return 0;	

}

