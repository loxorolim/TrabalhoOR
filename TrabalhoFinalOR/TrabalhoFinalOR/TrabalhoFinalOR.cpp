// TrabalhoFinalOR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "GraphPaths.h"

int _tmain(int argc, _TCHAR* argv[])
{
	TNode* graph;
	graph = read_file("teste.txt");
	int* ret = dijkstraMinCost(graph, 1, 5);
	printf("\n");
	int* ret2 = dijkstraMaxCost(graph, 1, 5);
	scanf_s("%d");
	return 0;
}

