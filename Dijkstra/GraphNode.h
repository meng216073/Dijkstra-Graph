#pragma once
#include <iostream>
class GraphNode
{
	friend class Graph;
	friend class NodeQueue;
private:
	GraphNode* next;
	std::string item;
	int weight;
	
public:
	GraphNode();
	~GraphNode();
	GraphNode(int i);
};
