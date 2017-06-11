/*
Author: Oguz Kaan Agac
21503895
Priority Queue for the GraphNode
*/

#pragma once
#include "GraphNode.h"
#include <string>
class NodeQueue
{
private:
	struct Queue 
	{
		Queue *next = NULL;
		int weight;
		GraphNode *node = NULL;
	};
	Queue *root = NULL;
	int SIZE;
public:
	NodeQueue();
	~NodeQueue();
	bool push(GraphNode*);
	GraphNode* top();
	GraphNode* pop();
	void printQueue();
	bool ifInQueue(std::string vertex);
	int printItems();
	int size();
};

