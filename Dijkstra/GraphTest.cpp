#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;


void foo(std::string& a)
{
	std::cout << a << std::endl;

}
int main()
{
	Graph x("dijkstra.txt");
	std::cout << "_INITAL GRAPH_ \n" << std::endl;
	x.printGraph();

	std::cout << "\n_DIJKSTRA SHORTEST PATH FROM S TO E_ \n" << std::endl;
	std::vector<std::string> dik = x.dijkstraShortestPath("S", "E");
	
	for (std::string q : dik)
	{
		std::cout << q << " -> ";
	}
	std::cout << ::endl;
	//std::string a;
	//x.breathFirstTraversal("S", foo);
	//Graph x;
	//x.addEdge("Ankara", "France", 10);
	//x.addEdge("France", "Italy", 6);
	//x.addEdge("Italy", "Rome", 1);
	//x.addEdge("Ankara", "Austuralia", 12);
	//x.addEdge("Austuralia", "Rome", 15);
	//x.editEdge("Ankara", "Austuralia", 98);
	//x.addEdge("Rome", "Ankara", 55);
	//x.printGraph();
	//std::cout << "\n ########################## \n" << std::endl;
	//x.removeEdge("Rome", "Ankara");
	//x.printGraph();
	//std::vector<std::string> dik = x.dijkstraShortestPath("Ankara", "Rome");
	return 0;
}
