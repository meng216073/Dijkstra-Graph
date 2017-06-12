#include "Graph.h"
#include <sstream>
#include <string>
#include <fstream>


// Default Constructor
Graph::Graph()
{
	defaultInitializer(0);
}

//copy constructor
Graph::Graph(const Graph& ref)
{
	defaultInitializer(ref.vertexSize);
	for (int i = 0; i < vertexSize; i++)
	{
		GraphNode *curr = ref.graph[i];
		std::string from = curr->item;
		while (curr)
		{
			GraphNode **pp = &(graph[nameMapping[from]]->next);
			GraphNode *temp = new GraphNode;
			temp->item = curr->item;
			temp->next = *pp;
			temp->weight = curr->weight;
			*pp = temp;
			curr = curr->next;
		}
	}
}

//construct from a text file
Graph::Graph(std::string filename)
{
	std::ifstream infile(filename.c_str());
	defaultInitializer(0);
	//mapNamesToInts(filename);
	std::string line;
	std::string from = "-1", to = "-1";
	int weight = 0;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		iss >> from >> to >> weight;
		addEdge(from, to, weight);
	}
}

// Common initializer for all constructors
void Graph::defaultInitializer(int graphSize)
{
	vertexSize = graphSize;
	edgeSize = 0;
	for (int i = 0; i < graphSize; i++)
	{
		GraphNode *temp = new GraphNode;
		temp->item = i;
		temp->next = NULL;
		temp->weight = 0;
		graph.push_back(temp);
	}
}

// Destructor
Graph::~Graph()
{
}

// Add a new vertex to the graph
bool Graph::addVertex(std::string vertex)
{
	mapStringToInt(vertex);
	//if exists, return
	if (vertexExists(nameMapping[vertex]))
		return false; 

	GraphNode *temp = new GraphNode;
	temp->item = vertex;
	temp->next = NULL;
	temp->weight = 0;
	graph.push_back(temp);
	vertexSize++;
	return true;
}

//Map a unique id to the given vertex
void Graph::mapStringToInt(std::string &vertex)
{
	// Map the vertex if it hasn't been mapped before
	if (nameMapping.find(vertex) == nameMapping.cend()) 
		nameMapping[vertex] = vertexSize;
}



void Graph::addEdge(std::string from, std::string to, int weight)
{
	/*If any of the vertices doesn't exist in the graph, first 
	create them then add the edge.*/
	addVertex(from);
	addVertex(to);

	GraphNode **pp = &(graph[nameMapping[from]]->next);
	GraphNode *temp = new GraphNode;
	temp->item = to;
	temp->next = *pp;
	temp->weight = weight;
	*pp = temp;
	edgeSize++;
}

// Check if the given vertex exists
bool Graph::vertexExists(int vertex)
{
	if (vertex >= vertexSize)
		return false;

	if (graph.size() >= vertexSize && 
		nameMapping[graph[vertex]->item] == vertex)
			return true;
	
	return false;
}

// Check if the given edge exists
bool Graph::edgeExists(std::string start, std::string end)
{
	if (!vertexExists(nameMapping[start]) || !vertexExists(nameMapping[end]))
		return false;

	GraphNode *temp = graph[nameMapping[start]];
	while (temp)
	{
		if (temp->item == end)
			return true;
		temp = temp->next;
	}
	return false;
}

// Edit the weight of an edge
void Graph::editEdge(std::string start, std::string end, int weight)
{
	bool a = edgeExists(start, end);
	if (!vertexExists(nameMapping[start]) ||
		!vertexExists(nameMapping[end]) || !edgeExists(start, end))
		return;

	GraphNode *temp = graph[nameMapping[start]];
	while (temp->item != end)
		temp = temp->next;
	temp->weight = weight;
	graph[nameMapping[end]]->weight = weight;
}

// Remove an edge
bool Graph::removeEdge(std::string start, std::string end)
{
  if (!vertexExists(nameMapping[start]) || 
	  !vertexExists(nameMapping[end]) || !edgeExists(start, end))
		return false;

  GraphNode *curr = graph[nameMapping[start]];
  GraphNode **pp = &graph[nameMapping[start]];

  while (curr)
  {
	  if (curr->item == end)
	  {
		  *pp = curr->next;
		  delete curr;
		  return true;
	  }
	  /* No need for a null check since function will
	  terminate once it successfully deletes the given node */
	  pp = &curr->next;
	  curr = curr->next;
  }
  return true;
}

std::vector<std::string> Graph::dijkstraShortestPath(std::string start, std::string end)
{
	// Shortest path
	std::vector<std::string> path; 

	// Starting node
	GraphNode* curr = graph[nameMapping[start]];

	// Priority Queue
	std::unique_ptr<NodeQueue> queue(new NodeQueue());

	// Mark visited to avoid inifinite loops
	std::vector<bool> visited(graph.size());

	// BFT (Breath First Traversal) with a priority queue
	while (nameMapping[curr->item] != nameMapping[end])
	{
		enqueueConnected(nameMapping[curr->item], visited, queue);
		curr = queue->pop();
		path.push_back(curr->item);
	}
	return path;
}

void Graph::enqueueConnected(int vertex, std::vector<bool>& visited, 
	std::unique_ptr<NodeQueue>& queue)
{
	GraphNode* curr = graph[vertex];
	int parentWeight = curr->weight;

	/* Queue all nodes that are connected to the inital 
	node  but haven't been visited before */
	while (curr)
	{		
		if (!visited[nameMapping[curr->item]])
		{
			curr->weight += parentWeight;
			queue->push(curr); 
			visited[nameMapping[curr->item]] = true;
		}
		curr = curr->next;
	}
}

void Graph::depthFirstTraversal(int& index, std::vector<bool>& visited, void visit(std::string&))
{
	GraphNode* curr = graph[index];
	visited[index] = true;
	visit(curr->item);
	while (curr)
	{
		index = nameMapping[curr->item];
		if (!visited[index])
			depthFirstTraversal(index, visited, visit);
		curr = curr->next;
	}
}
void Graph::depthFirstTraversal(std::string start, void visit(std::string&))
{
	// Mark visited to avoid inifinite loops
	std::vector<bool> visited(graph.size());
	int index = nameMapping[start];
	depthFirstTraversal(index, visited, visit);
  return;
}
void Graph::breathFirstTraversal(std::string start, void visit(std::string&))
{
	std::vector<bool> visited(graph.size());
	std::queue<int> queue;
	int index = nameMapping[start];
	queue.push(index);

	while (queue.size() != 0)
	{
		GraphNode* curr = graph[queue.front()];
		while (curr)
		{
			index = nameMapping[curr->item];
			if (!visited[index])
			{
				visit(curr->item);
				queue.push(index);
				visited[index] = true;
			}
			curr = curr->next;
		}
		queue.pop();
	}
}

// Getters
int Graph::getEdgeWeight(std::string start, std::string end)
{
	GraphNode *temp = graph[nameMapping[start]];
	if (!temp)
		return false;

	while (temp)
	{
		if (temp->item == end)
			return temp->weight;
		temp = temp->next;
	}

	return 0;
}

GraphNode * Graph::getVertexNode(int start)
{
	return graph[start];
}

int Graph::getNumVertices() const
{
	return vertexSize;
}

int Graph::getNumEdges() const
{
	return edgeSize;
}


void Graph::printGraph()
{
	for (int i = 0; i < vertexSize; i++)
	{
		GraphNode *temp = graph[i];
		if (!temp)
			std::cout << "[" << " / ]";
		while (temp)
		{
			std::cout << "[" << temp->item << " | ";
			temp = temp->next;
			if (temp)
				std::cout << "*] - " << temp->weight << " > ";
			else
				std::cout << "/]";
		}
		std::cout << std::endl;
	}
}