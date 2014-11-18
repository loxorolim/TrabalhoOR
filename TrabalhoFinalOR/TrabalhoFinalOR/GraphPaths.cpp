#include "GraphPaths.h"
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "graph.h"

int prepare_helpers(TNode *graph){
	TNode *p = graph;
	int i = 0;
	while (p){

		p->helper = i++;
		p = p->next;
	}
	return i;
}
void prepare_array(int* val, int size, int num){
	int i;
	for (i = 0; i < size; i++){
		val[i] = num;
	}
}

TNode* find_least_cost(TNode* nodes, int* dijValues){
	TNode*p = nodes->next;
	TNode*ret = nodes;
	while (p){
		if (dijValues[p->helper] != -1){
			if (dijValues[p->helper] < dijValues[ret->helper] || dijValues[ret->helper] == -1)
				ret = p;
		}

		p = p->next;
	}
	return ret;
}
TNode* find_highest_cost(TNode* nodes, int* dijValues){
	TNode*p = nodes->next;
	TNode*ret = nodes;
	while (p){
		if (dijValues[p->helper] != -1){
			if (dijValues[p->helper] > dijValues[ret->helper] || dijValues[ret->helper] == -1)
				ret = p;
		}

		p = p->next;
	}
	return ret;
}
int* dijkstraMaxCost(TNode* nodes, int start, int dest, int& rSize)
{
	TNode *p = find_node(nodes, start);
	if (p){
		int size = prepare_helpers(nodes);
		int* dijValues = (int*)malloc(sizeof(int)*size);
		int* fatherValues = (int*)malloc(sizeof(int)*size);
		int* edgeValues = (int*)malloc(sizeof(int)*size);
		prepare_array(dijValues, size, INT_MIN);
		prepare_array(fatherValues, size, -1);
		prepare_array(edgeValues, size, -1);

		dijValues[p->helper] = 0;
		fatherValues[p->helper] = p->number;

		while (dijValues[p->helper] != -1){
			if (p->number == dest)
				break;
			TEdge* e = p->edges;
			while (e){
				if (dijValues[e->node->helper] != -1){
					int val = dijValues[p->helper] + e->cost;
					if (val > dijValues[e->node->helper]){
						dijValues[e->node->helper] = val;
						fatherValues[e->node->helper] = p->number;
						edgeValues[e->node->helper] = e->cost;
					}

				}
				e = e->next;
			}
			dijValues[p->helper] = -1;
			p = find_highest_cost(nodes, dijValues);
		}

		//TNode * ret = NULL;
		//p = nodes;
		//while (p){
		//	ret = insert_node(ret, p->number);
		//	p = p->next;
		//}
		//p = nodes;
		//int i = 0;
		//while (p){
		//	if (p->number != fatherValues[i])
		//		insert_edge(ret, p->number, fatherValues[i], edgeValues[i]);
		//	i++;
		//	p = p->next;
		//}
		//save_file(ret, "cmc.txt");

		//		for (int i = 0; i < size; i++)
		//		printf("%d ", fatherValues[i]);

		TNode* aux = find_node(nodes, dest);
		int retSize = 0;
		int startnumber = aux->number;
		while (aux){
			aux = find_node(nodes, fatherValues[aux->helper]);
			if (!aux || aux->number == startnumber)
				break;
			retSize++;
			startnumber = aux->number;
		}
		retSize++;
		int * ret = (int*)malloc(sizeof(int)*retSize);
		aux = find_node(nodes, dest);
		for (int i = 0; i < retSize; i++){
			ret[retSize - i - 1] = aux->number;
			aux = find_node(nodes, fatherValues[aux->helper]);
		}
		if (ret[retSize-1] != dest || ret[0] != start)
		{
			free(ret);
			return NULL;
		}
		rSize = retSize;
		//for (int i = 0; i < retSize; i++)
		//	printf("%d ", ret[i]);


		//int retSize = 0;
		//TNode *aux = p;
		//while (aux){
		//	aux = find_node(nodes,fatherValues[aux->helper]);
		//	retSize++;
		//}
		//int * ret = (int*)malloc(sizeof(int)*size);
		//int i = retSize - 1;
		//while (p){
		//	ret[i--] = p->number;
		//	p = find_node(nodes,fatherValues[p->helper]);
		//	
		//}
		//for (i = 0; i < retSize; i++){
		//	printf("%d ", ret[i]);
		//}
		//return ret;

		//free_nodes(ret);
		free(dijValues);
		free(fatherValues);
		free(edgeValues);

		return ret;
	}
	return NULL;

}
int* dijkstraMaxHop(TNode* nodes, int start, int dest, int& rSize)
{
	TNode *p = find_node(nodes, start);
	if (p){
		int size = prepare_helpers(nodes);
		int* dijValues = (int*)malloc(sizeof(int)*size);
		int* fatherValues = (int*)malloc(sizeof(int)*size);
		int* edgeValues = (int*)malloc(sizeof(int)*size);
		prepare_array(dijValues, size, INT_MIN);
		prepare_array(fatherValues, size, -1);
		prepare_array(edgeValues, size, -1);

		dijValues[p->helper] = 0;
		fatherValues[p->helper] = p->number;

		while (dijValues[p->helper] != -1){
			if (p->number == dest)
				break;
			TEdge* e = p->edges;
			while (e){
				if (dijValues[e->node->helper] != -1){
					int val = dijValues[p->helper] + 1;
					if (val > dijValues[e->node->helper]){
						dijValues[e->node->helper] = val;
						fatherValues[e->node->helper] = p->number;
						edgeValues[e->node->helper] = e->cost;
					}

				}
				e = e->next;
			}
			dijValues[p->helper] = -1;
			p = find_highest_cost(nodes, dijValues);
		}

		//TNode * ret = NULL;
		//p = nodes;
		//while (p){
		//	ret = insert_node(ret, p->number);
		//	p = p->next;
		//}
		//p = nodes;
		//int i = 0;
		//while (p){
		//	if (p->number != fatherValues[i])
		//		insert_edge(ret, p->number, fatherValues[i], edgeValues[i]);
		//	i++;
		//	p = p->next;
		//}
		//save_file(ret, "cmc.txt");

		//		for (int i = 0; i < size; i++)
		//		printf("%d ", fatherValues[i]);

		TNode* aux = find_node(nodes, dest);
		int retSize = 0;
		int startnumber = aux->number;
		while (aux){
			aux = find_node(nodes, fatherValues[aux->helper]);
			if (!aux || aux->number == startnumber)
				break;
			retSize++;
			startnumber = aux->number;
		}
		retSize++;
		int * ret = (int*)malloc(sizeof(int)*retSize);
		aux = find_node(nodes, dest);
		for (int i = 0; i < retSize; i++){
			ret[retSize - i - 1] = aux->number;
			aux = find_node(nodes, fatherValues[aux->helper]);
		}
		if (ret[retSize - 1] != dest || ret[0] != start)
		{
			free(ret);
			return NULL;
		}
		rSize = retSize;
		//for (int i = 0; i < retSize; i++)
		//	printf("%d ", ret[i]);


		//int retSize = 0;
		//TNode *aux = p;
		//while (aux){
		//	aux = find_node(nodes,fatherValues[aux->helper]);
		//	retSize++;
		//}
		//int * ret = (int*)malloc(sizeof(int)*size);
		//int i = retSize - 1;
		//while (p){
		//	ret[i--] = p->number;
		//	p = find_node(nodes,fatherValues[p->helper]);
		//	
		//}
		//for (i = 0; i < retSize; i++){
		//	printf("%d ", ret[i]);
		//}
		//return ret;

		//free_nodes(ret);
		free(dijValues);
		free(fatherValues);
		free(edgeValues);

		return ret;
	}
	return NULL;

}
int* dijkstraMinCost(TNode* nodes, int start, int dest, int& rSize)
{
	TNode *p = find_node(nodes, start);
	if (p){
		int size = prepare_helpers(nodes);
		int* dijValues = (int*)malloc(sizeof(int)*size);
		int* fatherValues = (int*)malloc(sizeof(int)*size);
		int* edgeValues = (int*)malloc(sizeof(int)*size);
		prepare_array(dijValues, size, INT_MAX);
		prepare_array(fatherValues, size, -1);
		prepare_array(edgeValues, size, -1);

		dijValues[p->helper] = 0;
		fatherValues[p->helper] = p->number;

		while (dijValues[p->helper] != -1){
			if (p->number == dest)
				break;
			TEdge* e = p->edges;
			while (e){
				if (dijValues[e->node->helper] != -1){
					int val = dijValues[p->helper] + e->cost;
					if (val < dijValues[e->node->helper]){
						dijValues[e->node->helper] = val;
						fatherValues[e->node->helper] = p->number;
						edgeValues[e->node->helper] = e->cost;
					}

				}
				e = e->next;
			}
			dijValues[p->helper] = -1;
			p = find_least_cost(nodes, dijValues);
		}

		//TNode * ret = NULL;
		//p = nodes;
		//while (p){
		//	ret = insert_node(ret, p->number);
		//	p = p->next;
		//}
		//p = nodes;
		//int i = 0;
		//while (p){
		//	if (p->number != fatherValues[i])
		//		insert_edge(ret, p->number, fatherValues[i], edgeValues[i]);
		//	i++;
		//	p = p->next;
		//}
		//save_file(ret, "cmc.txt");

//		for (int i = 0; i < size; i++)
	//		printf("%d ", fatherValues[i]);

		TNode* aux = find_node(nodes, dest);
		int retSize = 0;
		int startnumber = aux->number;
		while (aux){
			aux = find_node(nodes, fatherValues[aux->helper]);
			if (!aux || aux->number == startnumber)
				break;
			retSize++;
			startnumber = aux->number;
		}
		retSize++;
		int * ret = (int*)malloc(sizeof(int)*retSize);
		aux = find_node(nodes, dest);
		for (int i = 0; i < retSize; i++){
			ret[retSize - i - 1] = aux->number;
			aux = find_node(nodes, fatherValues[aux->helper]);
		}
		if (ret[retSize-1] != dest|| ret[0] != start)
		{
			free(ret);
			return NULL;
		}
		rSize = retSize;
		//for (int i = 0; i < retSize; i++)
		//	printf("%d ", ret[i]);


		//int retSize = 0;
		//TNode *aux = p;
		//while (aux){
		//	aux = find_node(nodes,fatherValues[aux->helper]);
		//	retSize++;
		//}
		//int * ret = (int*)malloc(sizeof(int)*size);
		//int i = retSize - 1;
		//while (p){
		//	ret[i--] = p->number;
		//	p = find_node(nodes,fatherValues[p->helper]);
		//	
		//}
		//for (i = 0; i < retSize; i++){
		//	printf("%d ", ret[i]);
		//}
		//return ret;

		//free_nodes(ret);
		free(dijValues);
		free(fatherValues);
		free(edgeValues);

		return ret;
	}
	return NULL;

}
int* dijkstraMinHop(TNode* nodes, int start, int dest, int& rSize)
{
	TNode *p = find_node(nodes, start);
	if (p){
		int size = prepare_helpers(nodes);
		int* dijValues = (int*)malloc(sizeof(int)*size);
		int* fatherValues = (int*)malloc(sizeof(int)*size);
		int* edgeValues = (int*)malloc(sizeof(int)*size);
		prepare_array(dijValues, size, INT_MAX);
		prepare_array(fatherValues, size, -1);
		prepare_array(edgeValues, size, -1);

		dijValues[p->helper] = 0;
		fatherValues[p->helper] = p->number;

		while (dijValues[p->helper] != -1){
			if (p->number == dest)
				break;
			TEdge* e = p->edges;
			while (e){
				if (dijValues[e->node->helper] != -1){
					int val = dijValues[p->helper] + 1;
					if (val < dijValues[e->node->helper]){
						dijValues[e->node->helper] = val;
						fatherValues[e->node->helper] = p->number;
						edgeValues[e->node->helper] = e->cost;
					}

				}
				e = e->next;
			}
			dijValues[p->helper] = -1;
			p = find_least_cost(nodes, dijValues);
		}

		//TNode * ret = NULL;
		//p = nodes;
		//while (p){
		//	ret = insert_node(ret, p->number);
		//	p = p->next;
		//}
		//p = nodes;
		//int i = 0;
		//while (p){
		//	if (p->number != fatherValues[i])
		//		insert_edge(ret, p->number, fatherValues[i], edgeValues[i]);
		//	i++;
		//	p = p->next;
		//}
		//save_file(ret, "cmc.txt");

		//		for (int i = 0; i < size; i++)
		//		printf("%d ", fatherValues[i]);

		TNode* aux = find_node(nodes, dest);
		int retSize = 0;
		int startnumber = aux->number;
		while (aux){
			aux = find_node(nodes, fatherValues[aux->helper]);
			if (!aux || aux->number == startnumber)
				break;
			retSize++;
			startnumber = aux->number;
		}
		retSize++;
		int * ret = (int*)malloc(sizeof(int)*retSize);
		aux = find_node(nodes, dest);
		for (int i = 0; i < retSize; i++){
			ret[retSize - i - 1] = aux->number;
			aux = find_node(nodes, fatherValues[aux->helper]);
		}
		if (ret[retSize - 1] != dest || ret[0] != start)
		{
			free(ret);
			return NULL;
		}
		rSize = retSize;
		//for (int i = 0; i < retSize; i++)
		//	printf("%d ", ret[i]);


		//int retSize = 0;
		//TNode *aux = p;
		//while (aux){
		//	aux = find_node(nodes,fatherValues[aux->helper]);
		//	retSize++;
		//}
		//int * ret = (int*)malloc(sizeof(int)*size);
		//int i = retSize - 1;
		//while (p){
		//	ret[i--] = p->number;
		//	p = find_node(nodes,fatherValues[p->helper]);
		//	
		//}
		//for (i = 0; i < retSize; i++){
		//	printf("%d ", ret[i]);
		//}
		//return ret;

		//free_nodes(ret);
		free(dijValues);
		free(fatherValues);
		free(edgeValues);

		return ret;
	}
	return NULL;

}
int dijkstra(TNode* nodes, int start){
	//reset_helper(nodes, INT_MAX);
	TNode *p = find_node(nodes, start);
	if (p){
		int size = prepare_helpers(nodes);
		int* dijValues = (int*)malloc(sizeof(int)*size);
		int* fatherValues = (int*)malloc(sizeof(int)*size);
		int* edgeValues = (int*)malloc(sizeof(int)*size);
		prepare_array(dijValues, size, INT_MAX);
		prepare_array(fatherValues, size, -1);
		prepare_array(edgeValues, size, -1);

		dijValues[p->helper] = 0;
		fatherValues[p->helper] = p->number;

		while (dijValues[p->helper] != -1){
			//		if (p->number == end)
			//			break;
			TEdge* e = p->edges;
			while (e){
				if (dijValues[e->node->helper] != -1){
					int val = dijValues[p->helper] + e->cost;
					if (val < dijValues[e->node->helper]){
						dijValues[e->node->helper] = val;
						fatherValues[e->node->helper] = p->number;
						edgeValues[e->node->helper] = e->cost;
					}

				}
				e = e->next;
			}
			dijValues[p->helper] = -1;
			p = find_least_cost(nodes, dijValues);
		}

		TNode * ret = NULL;
		p = nodes;
		while (p){
			ret = insert_node(ret, p->number);
			p = p->next;
		}
		p = nodes;
		int i = 0;
		while (p){
			if (p->number != fatherValues[i])
				insert_edge(ret, p->number, fatherValues[i], edgeValues[i]);
			i++;
			p = p->next;
		}
		save_file(ret, "cmc.txt");
		free_nodes(ret);
		free(dijValues);
		free(fatherValues);
		free(edgeValues);
		return 1;
	}
	return 0;


	//int retSize = 0;
	//TNode *aux = p;
	//while (aux){
	//	aux = find_node(nodes,fatherValues[aux->helper]);
	//	retSize++;
	//}
	//int * ret = (int*)malloc(sizeof(int)*size);
	//int i = retSize - 1;
	//while (p){
	//	ret[i--] = p->number;
	//	p = find_node(nodes,fatherValues[p->helper]);
	//	
	//}
	//for (i = 0; i < retSize; i++){
	//	printf("%d ", ret[i]);
	//}
	//return ret;

}