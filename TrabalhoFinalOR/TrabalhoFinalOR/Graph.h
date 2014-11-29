#ifndef GRAPH_H
#define GRAPH_H

struct edge;

typedef struct node {
	int number;
	struct node *next;
	struct edge *edges;
	int helper;
} TNode;

typedef struct edge {
	struct node *node;
	struct edge *next;
	int cost;
	int xValue;
} TEdge;


TNode * new_node(int number, TNode *next);

TEdge * new_edge(TNode *node, TEdge *next, int cost);

void free_edges(TEdge *edge);

void free_nodes(TNode *node);

void print_graph(TNode *graph);

TNode * insert_node(TNode *nodes, int val);

void insert_edge(TNode *graph, int origin, int dest, int cost);

void insert_edge_in_node(TNode *origin, TNode *dest, int cost);

TNode * remove_node(TNode *node, int number);

TNode * remove_edge_from_node(TNode *node, int number);

TNode * find_node(TNode *node, int number);

void remove_edge(TNode *node, int number1, int number2);

int is_connected(TNode *nodes);

void mark_neighbours(TNode *nodes);

int count_nodes(TNode* nodes);

int count_edge_sequence(TEdge *edge);

void count_nodes_and_edges(TNode *node, int * nodes, int * edges);

void save_file(TNode *node, char* name);

TNode * read_file(char* name);

TNode *read_file2(char* name);

TNode *GraphRandomized(int n);

TNode *CompleteGraph(int n);

TNode *OneDirectionGraph(int n);

TNode *OneDirectionDrecreaseFlowGraph(int n);

#endif

//#include "stdafx.h"
//#include <vector>
//
//using namespace std;
//
//class Info
//{
//	private:
//	int cost, xval;
//	public:
//	Info(int c, int x)
//	{
//		cost = c;
//		xval = x;
//	}
//	int getCost()
//	{
//		return cost;
//	}
//	int getXValue()
//	{
//		return xval;
//	}
//	void setCost(int c)
//	{
//		cost = c;
//	}
//	void setXValue(int x)
//	{
//		xval = x;
//	}
//};
//class Graph
//{
//
//	private:
//		vector<vector<Info*>> matrix;
//	
//	public:
//		Graph(int n)
//		{
//			//inicializa matriz com tudo -1
//			for (int j = 0; j < n; j++)
//			{
//				vector<Info*> line;
//				for (int i = 0; i < n; i++)
//				{
//					Info* inf = new Info(-1,-1);
//					line.push_back(inf);
//				}
//					
//				matrix.push_back(line);
//			}
//
//		}
//		~Graph()
//		{
//
//		}
//		void addEdge(int source, int dest, int cost)
//		{
//			matrix[source][dest]->setCost(cost);
//		}
//		vector<int> getPath(int source, int dest)
//		{
//
//		}
//		vector<int> getNextNeighbours(int source)
//		{
//			vector<int> neighbours;
//			for (int i = 0; i < matrix.size(); i++)
//				if (matrix[source][i]->getCost > -1)
//					neighbours.push_back(i);
//
//		}
//		vector<vector<Info*>>* getMatrix()
//		{
//			return &matrix;
//		}
//};
//
//void fordFulkerson(Graph *g, int source, int dest)
//{
//	int size = g->getMatrix()->size();
//	
//	for (int i = 0; i < size; i++)
//	{
//		xValues.push_back(0);
//	}
//}