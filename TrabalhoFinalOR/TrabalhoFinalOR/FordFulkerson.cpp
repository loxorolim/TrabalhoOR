#include "stdafx.h"
#include "Graph.h"
#include "GraphPaths.h"
#include <limits.h>
TNode* createGraphCopy(TNode *g)
{
	TNode* ret = NULL;
	TNode *aux = g;
	while (aux)
	{
		ret = insert_node(ret, aux->number);
		aux = aux->next;
	}
	aux = g;
	while (aux)
	{
		TEdge* e = aux->edges;
		while (e)
		{
			if (e->cost == e->xValue)
			{
				insert_edge(ret, e->node->number, aux->number, e->xValue);
			}
			else if (e->xValue == 0)
			{
				insert_edge(ret, aux->number, e->node->number, e->cost);
			}
			else if (e->cost - e->xValue > 0)
			{
				insert_edge(ret, aux->number, e->node->number, e->cost - e->xValue);
				insert_edge(ret, e->node->number, aux->number, e->xValue);
			}
			e = e->next;
		}
		aux = aux->next;
	}
	return ret;

}
int* getPath(TNode* g, int source, int dest, int pathOption, int &pathSize)
{
	switch (pathOption)
	{
	case 0:
		return dijkstraMinCost(g, source, dest,pathSize);
	case 1:
		return dijkstraMaxCost(g, source, dest,pathSize);
	case 2:
		return dijkstraMinHop(g, source, dest, pathSize);
	case 3:
		return dijkstraMaxHop(g, source, dest, pathSize);
	default:
		break;
	}
	return NULL;
}
TEdge* getEdge(TNode*g, int num1, int num2)
{
	TNode* aux = find_node(g, num1);
	TNode* aux2 = find_node(g, num2);
	TEdge* e = aux->edges;
	while (e && e->node->number != aux2->number)
	{
		e = e->next;
	}
	return e;
}
int getMaxFlowFromPath(TNode* g,int* path, int size)
{
	int ret = INT_MAX;
	for (int i = 0; i < size-1; i++)
	{
		TEdge* e = getEdge(g, path[i], path[i + 1]);	
		if (e->cost < ret)
			ret = e->cost;
	}
	return ret;
}

int FordFulkerson(TNode *g, int source, int dest, int pathOption)
{
	TNode *aux = g;
	while (aux)
	{
		TEdge* e = aux->edges;
		while (e)
		{
			e->xValue = 0;
			e = e->next;
		}
		aux = aux->next;
	}
	TNode *gcopy = createGraphCopy(g);
	int pathSize = -1;
	int* path = getPath(gcopy, source, dest,pathOption,pathSize);
	int numRounds = 0;
	//print_graph(gcopy);
	while (path)
	{
		numRounds++;
		int maxFlow = getMaxFlowFromPath(gcopy, path, pathSize);
		//for (int i = 0; i < pathSize; i++)
		//	printf("%d ", path[i]);
		//printf("\n");
		for (int i = 0; i < pathSize-1; i++)
		{
			TEdge* e = getEdge(g, path[i], path[i + 1]);
			if (e)
			{
				//e->cost -= maxFlow;
				e->xValue += maxFlow;
			}
			else
			{
				e = getEdge(g, path[i+1], path[i]);
				//e->cost += maxFlow;
				e->xValue -= maxFlow;
			}
		}
		free_nodes(gcopy);
		gcopy = createGraphCopy(g);
		path = getPath(gcopy, source, dest, pathOption, pathSize);
		//print_graph(gcopy);
	}
	TEdge*e = g->edges;
	int f = 0;
	while (e)
	{
		f += e->xValue;
		e = e->next;
	}
//	printf("%d", f);
	return numRounds;

	//print_graph(gcopy);


}