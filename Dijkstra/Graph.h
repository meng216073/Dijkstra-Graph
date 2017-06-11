#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <map>
#include <queue>
#include "GraphInterface.h"
#include "GraphNode.h"
#include "NodeQueue.h"


class Graph : public GraphInterface <std::string>
{
private:
	int vertexSize;
	int edgeSize;
	std::vector<GraphNode*> graph;
	std::map<std::string, int> nameMapping;
	void defaultInitializer(int size);
	void enqueueConnected(int vertex, std::vector<bool>& visited, std::unique_ptr<NodeQueue>& queue);
	void mapStringToInt(std::string &vertex);
	void depthFirstTraversal(int& index, std::vector<bool>& visited, void visit(std::string&));

public:
	Graph();
	Graph(const Graph& ref);
	Graph(std::string filename);
	~Graph();
	virtual int getNumVertices() const;
	virtual int getNumEdges() const;
	virtual int getEdgeWeight(std::string start, std::string end);
	virtual bool addVertex(std::string vertex);
	virtual bool removeEdge(std::string start, std::string end);
	virtual void  addEdge(std::string from, std::string to, int weight);
	virtual void depthFirstTraversal(std::string start, void visit(std::string&));
	virtual void breathFirstTraversal(std::string start, void visit(std::string&));
	bool vertexExists(int vertex);
	bool edgeExists(std::string start, std::string end);
	void editEdge(std::string start, std::string end, int weight);
	void printGraph();
	GraphNode* getVertexNode(int vertex);
	std::vector<std::string> dijkstraShortestPath(std::string start, std::string end);
};
