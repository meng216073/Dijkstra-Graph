/*
Author: Oguz Kaan Agac
21503895
Priority Queue implementation
Nodes are prioritized based on their weights
*/
#include "NodeQueue.h"

NodeQueue::NodeQueue()
{
	root = NULL;
	SIZE = 0;
}

NodeQueue::~NodeQueue()
{
	
	while (root)
	{
		Queue *temp = root;
		root = root->next;
		delete temp;
	}
}

bool NodeQueue::push(GraphNode* InputNode)
{
	Queue* temp = new Queue();
	Queue** pp = &root;
	Queue* curr = root;
	
	temp->weight = InputNode->weight;
	temp->node = InputNode;
	
	while (curr && curr->weight < InputNode->weight)
	{
		pp = &(curr->next);
		curr = curr->next;
	}
	temp->next = curr;
	*pp = temp;
	SIZE++;
	return false;
}

GraphNode* NodeQueue::top()
{
	if (!root)
		return NULL;
	return root->node;
}

GraphNode* NodeQueue::pop()
{
	if (!root)
		return NULL;
	Queue *temp = root;
	root = root->next;	
	SIZE--;
	GraphNode* returnNode = temp->node;
	delete temp;
	return returnNode;

}

void NodeQueue::printQueue()
{
	Queue *temp = root;
	while (temp)
	{
		std::cout << temp->weight << " -> ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

bool NodeQueue::ifInQueue(std::string vertex)
{
	if (!root)
		return false;
	Queue *temp = root;
	while (temp)
	{
		if (temp->node->item == vertex)
			return true;
		temp = temp->next;
	}
	return false;
}

int NodeQueue::printItems()
{
	Queue *temp = root;
	while (temp)
	{
		std::cout << temp->node->item << " -> ";
		temp = temp->next;
	}
	std::cout << std::endl;
	return 0;
}

int NodeQueue::size()
{
	return SIZE;
}

