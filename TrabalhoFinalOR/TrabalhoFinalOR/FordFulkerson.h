#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H
#include "Graph.h"
#include "GraphPaths.h"

TNode* createGraphCopy(TNode *g);
int FordFulkerson(TNode *g, int source, int dest, int pathOption);

#endif