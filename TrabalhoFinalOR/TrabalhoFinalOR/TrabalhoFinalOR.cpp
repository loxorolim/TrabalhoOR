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
	int n = 200;
	//graph = GraphRandomized(n);
	//graph = CompleteGraph(n);
	//graph = OneDirectionDrecreaseFlowGraph(n);
	//graph = OneDirectionGraph(n);
	print_graph(graph);
	//int size = -1;
	//int* ret = dijkstraMinCost(graph, 1, 6,size);
	//printf("\n");
	//int* ret2 = dijkstraMaxCost(graph, 5, 1,size);
	FILE *f;
	fopen_s(&f, "Results.txt", "w");
	if (f)
	{

		fprintf_s(f, "-----------------------Graph Size: %d -----------------------\n\n", 10);
		for (int k = 0; k < 4; k++)
		{

			switch (k)
			{
			case 0:
				graph = GraphRandomized(10);
				fprintf_s(f, "***************Randomized Graph***************\n\n");
				break;
			case 1:
				graph = CompleteGraph(10);
				fprintf_s(f, "***************Complete Graph***************\n\n");
				break;
			case 2:
				graph = OneDirectionDrecreaseFlowGraph(10);
				fprintf_s(f, "***************One Direction Decrease Flow Graph***************\n\n");
				break;
			case 3:
				OneDirectionGraph(10);
				fprintf_s(f, "***************One Direction Flow Graph***************\n\n");
				break;
			default:
				break;

			}

			for (int i = 0; i < 4; i++)
			{
				//time_t start, end;
				//time(&start);
				if (i == 0)
					fprintf_s(f, "&&&Minimum Cost Path&&&\n\n");
				if (i == 1)
					fprintf_s(f, "&&&Maximum Cost Path&&&\n\n");
				if (i == 2)
					fprintf_s(f, "&&&Minimum Hop Path&&&\n\n");
				if (i == 3)
					fprintf_s(f, "&&&Maximum Hop Path&&&\n\n");

				const clock_t begin_time = clock();
				int nRounds = FordFulkerson(graph, 1, 10, i);
				float dif = float(clock() - begin_time) / CLOCKS_PER_SEC;
				fprintf_s(f, "Number of rounds: %d\n", nRounds);
				fprintf_s(f, "Processing time in seconds: %f\n\n", dif);
				//time(&end);
				//double dif = difftime(end, start);
				//printf(" %f \n", dif);
			}
		}

		for (int j = 25; j < n+1; j += 25)
		{
			printf("Fazendo grafo de tamanho: %d\n", j);
			fprintf_s(f, "-----------------------Graph Size: %d -----------------------\n\n", j);
			for (int k = 0; k < 4; k++)
			{
				printf("Com grafo do tipo : %d\n", k);
				switch (k)
				{
					case 0:
						graph = GraphRandomized(j);
						fprintf_s(f, "***************Randomized Graph***************\n\n");
						break;
					case 1:
						graph = CompleteGraph(j);
						fprintf_s(f, "***************Complete Graph***************\n\n");
						break;
					case 2:
						graph = OneDirectionDrecreaseFlowGraph(j);
						fprintf_s(f, "***************One Direction Decrease Flow Graph***************\n\n");
						break;
					case 3:
						OneDirectionGraph(j);
						fprintf_s(f, "***************One Direction Flow Graph***************\n\n");
						break;
					default:
						break;

				}

				for (int i = 0; i < 4; i++)
				{
					printf("E metodo : %d\n", i);
					//time_t start, end;
					//time(&start);
					if (i == 0)
						fprintf_s(f, "&&&Minimum Cost Path&&&\n\n");
					if (i == 1)
						fprintf_s(f, "&&&Maximum Cost Path&&&\n\n");
					if (i == 2)
						fprintf_s(f, "&&&Minimum Hop Path&&&\n\n");
					if (i == 3)
						fprintf_s(f, "&&&Maximum Hop Path&&&\n\n");
					
					const clock_t begin_time = clock();
					int nRounds = FordFulkerson(graph, 1, j, i);
					float dif = float(clock() - begin_time) / CLOCKS_PER_SEC;
					fprintf_s(f, "Number of rounds: %d\n", nRounds);
					fprintf_s(f, "Processing time in seconds: %f\n\n", dif);
					//time(&end);
					//double dif = difftime(end, start);
					//printf(" %f \n", dif);
				}
			}

		}

	}
	fclose(f);

	free(graph);


	//scanf_s("%d");
	return 0;
}

