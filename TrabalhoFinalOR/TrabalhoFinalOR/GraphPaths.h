#ifndef GRAPHPATHS_H
#define GRAPHPATHS_H

#include "Graph.h"

int dijkstra(TNode* nodes, int start);
int* dijkstraMinCost(TNode* nodes, int start, int dest, int &rSize);
int* dijkstraMaxCost(TNode* nodes, int start, int dest, int &rSize);
int* dijkstraMinHop(TNode* nodes, int start, int dest, int& rSize);
int* dijkstraMaxHop(TNode* nodes, int start, int dest, int& rSize);
void prepare_array(int* val, int size, int num);
int prepare_helpers(TNode *graph);
#endif