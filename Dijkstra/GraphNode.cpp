#include "GraphNode.h"
GraphNode::GraphNode()
{
	next = NULL;
	item = '0';
	weight = 0;
}

GraphNode::~GraphNode()
{

}

GraphNode::GraphNode(int i)
{
	next = NULL;
	item = '0';
	weight = i;
}
