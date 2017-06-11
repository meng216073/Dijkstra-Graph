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
	x.printGraph();
	//std::vector<std::string> dik = x.dijkstraShortestPath("S", "E");
	std::string a;
	x.breathFirstTraversal("S", foo);
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
	//for (std::string q : dik)
	//{
	//	std::cout << q << " -> ";
	//}
	//std::cout << ::endl;
	return 0;
}
