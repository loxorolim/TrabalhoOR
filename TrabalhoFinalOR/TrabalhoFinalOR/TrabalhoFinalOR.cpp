// TrabalhoFinalOR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "GraphPaths.h"
#include "FordFulkerson.h"

int _tmain(int argc, _TCHAR* argv[])
{
	TNode* graph;
	graph = read_file("teste.txt");
	int size = -1;
	int* ret = dijkstraMinCost(graph, 1, 6,size);
	printf("\n");
	int* ret2 = dijkstraMaxCost(graph, 5, 1,size);

	FordFulkerson(graph, 1, 7, 0);
	FordFulkerson(graph, 1, 7, 1);
	FordFulkerson(graph, 1, 7, 2);
	FordFulkerson(graph, 1, 7, 3);
	scanf_s("%d");
	return 0;
}

