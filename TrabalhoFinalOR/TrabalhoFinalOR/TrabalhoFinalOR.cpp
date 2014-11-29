// TrabalhoFinalOR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "GraphPaths.h"
#include "FordFulkerson.h"3
#include <random>
#include <time.h>
#include <chrono>


int _tmain(int argc, _TCHAR* argv[])
{
	srand(NULL);
	TNode* graph= NULL;
	//graph = insert_node(graph, 1);
	//graph = insert_node(graph, 2);
	//graph = insert_node(graph, 3);
	//insert_edge(graph, 1, 2, 3);
	//insert_edge(graph, 2, 1, 3);
	//insert_edge(graph, 1, 3, 3);
	//insert_edge(graph, 3, 1, 3);
	//insert_edge(graph, 2, 3, 3);
	//insert_edge(graph, 3, 2, 3);
	//graph = read_file("teste.txt");
	//graph = read_file2("Instancia1.txt");
	int n = 100;
	//graph = GraphRandomized(n);
	//graph = CompleteGraph(n);
	//graph = OneDirectionDrecreaseFlowGraph(n);
	//graph = OneDirectionGraph(n);
	print_graph(graph);
	//int size = -1;
	//int* ret = dijkstraMinCost(graph, 1, 6,size);
	//printf("\n");
	//int* ret2 = dijkstraMaxCost(graph, 5, 1,size);
	for (int i = 0; i < 4; i++)
	{
		//time_t start, end;
		//time(&start);
		const clock_t begin_time = clock();
		FordFulkerson(graph, 1, n, i);
		float dif = float(clock() - begin_time) / CLOCKS_PER_SEC;
		//time(&end);
		//double dif = difftime(end, start);
		printf(" %f \n", dif);
	}
	free(graph);


	scanf_s("%d");
	return 0;
}

