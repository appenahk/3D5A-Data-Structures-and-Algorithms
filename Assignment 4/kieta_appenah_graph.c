//Kieta Appenah 14/12/2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_NODE_CONNECTIONS 10
#define MAX_NODES 26
#define INF 99999999 

typedef struct Graph Graph;
typedef struct Graph_Node Graph_Node;

struct Graph_Node 
{
	char data;
	bool visited;

	Graph_Node* edges[MAX_NODE_CONNECTIONS];
	int number_of_edges;
	int weights[MAX_NODE_CONNECTIONS];

	// variables for working out dijkstra
	bool is_permanent;
	Graph_Node* parent;
	int shortest_length;
	
};

struct Graph 
{
	Graph_Node* vertices[MAX_NODES];
	int number_of_vertices;
};

//create new vertex with default data
Graph_Node* newVertex(char data) 
{
	Graph_Node* graph_node = (Graph_Node*)malloc(sizeof(Graph_Node));
	graph_node->data = data;
	graph_node->visited = false;
	graph_node->number_of_edges = 0;
	graph_node->is_permanent = false;
	graph_node->parent = NULL;
	graph_node->shortest_length = INF;
	
	return graph_node;
}
// add an edge in both directions - to-from and also from-to
void add_edge_undirected(Graph_Node *start, Graph_Node *end, int cost)
 {
	assert(start);
	assert(end);
	//find closest empty
	int i = 0;
	while (i < start->number_of_edges) 
	{
		i++;
	}
	//go to start vertex put edge in and put weight
	start->edges[i] = end;
	start->weights[i] = cost;
	start->number_of_edges++;

	int j = 0;
	while (j < end->number_of_edges)
	{
		j++;
	}
	//go to end vertex put edge in and put weight
	end->edges[j] = start;
	end->weights[j] = cost;
	end->number_of_edges++;

}
//make new graph by adding all the vertices, keep count
void newGraph(Graph * graph) 
{	
	graph->number_of_vertices = 0;
	
	for (int i = 'A'; i <= 'L'; i++) 
	{
		graph->vertices[i - 'A'] = newVertex((char)i);
		graph->number_of_vertices++;
	}
}
//reset the visited vertices so as to use the data again
void reset_graph(Graph* graph)
 {
	for (int i = 0; i < graph->number_of_vertices; i++) 
	{
		graph->vertices[i]->visited = false;
	}
}
bool dfs(Graph* graph, char start_at, char find_value) 
{
	assert(graph);
	assert(start_at);

	graph->vertices[start_at - 'A']->visited = true;
	printf("%c ", start_at);
	bool found = false;
	if (graph == NULL) 
	{
		printf("NULL graph\n");
		return false;
	}
	else
	 {
		if (graph->vertices[start_at- 'A']->data == find_value)
		{
			printf("\n Target Found - HALT and stop \n");
			return true;
		}
		else 
		{
			//if not found cycle through edges in start_at variable and if unvisited recurse throught the function till found/not 
			for (int i = 0; i < graph->vertices[start_at -'A']->number_of_edges; i++) 
			{
				if (graph->vertices[start_at -'A']->edges[i]->visited == false) 
				{
					found = dfs(graph, graph->vertices[start_at-'A']->edges[i]->data, find_value);

					if (found == true) 
					{				
						return true;
					}
				}
			}
		}

	}
	return false;
}

/*
bool dijkstra(Graph* graph, char start_at, char find_value)
{
	if (graph == NULL) 
	{
		printf("\nNULL graph\n");
		return false;
	}

	if (start < 'A' || start > 'L') 
{
		return false;
	}
	int temp = 0;
	graph->vertices[start_at  - 'A'].shortest_length = 0;
	Graph_Node* curr = graph->vertices[start_at - 'A'];
	graph->vertices[curr].is_permanent = true;
	while (curr != find_value)
	{
		int distcurr = graph->vertices[curr].shortest_length;
		int smalldist = INF;
		for (int i = 0; i < graph->number_of_vertices; i++)
		{
			if (graph->vertices[i].is_permanent = false)
			{
				int path = graph->vertices[curr].shortest_length + graph->vertices[curr]->weights[i];
				if (path < graph->vertices[i].shortest_length)
				{
					graph->vertices[i].shortest_length = path;
					graph->vertices[i].parent = graph->vertices[curr].parent;
				}
				if (graph->vertices[i].shortest_length < smalldist)
				{
					smalldist = graph->vertices[i].shortest_length;
					temp = i;
				}
			}
			curr = temp;
			graph->vertices[curr].is_permanent = true;
		}
	}
	return true;

}
*/


int main() 
{

	Graph *my_graph = (Graph*)malloc(sizeof(Graph));
	newGraph(my_graph);

	add_edge_undirected(my_graph->vertices['A' - 'A'], my_graph->vertices['B' - 'A'], 1);
	add_edge_undirected(my_graph->vertices['B' - 'A'], my_graph->vertices['C' - 'A'], 2);
	add_edge_undirected(my_graph->vertices['B' - 'A'], my_graph->vertices['D' - 'A'], 2);
	add_edge_undirected(my_graph->vertices['C' - 'A'], my_graph->vertices['E' - 'A'], 3);
	add_edge_undirected(my_graph->vertices['C' - 'A'], my_graph->vertices['F' - 'A'], 2);
	add_edge_undirected(my_graph->vertices['D' - 'A'], my_graph->vertices['G' - 'A'], 2);
	add_edge_undirected(my_graph->vertices['F' - 'A'], my_graph->vertices['H' - 'A'], 1);
	add_edge_undirected(my_graph->vertices['F' - 'A'], my_graph->vertices['I' - 'A'], 2);
	add_edge_undirected(my_graph->vertices['F' - 'A'], my_graph->vertices['J' - 'A'], 4);
	add_edge_undirected(my_graph->vertices['G' - 'A'], my_graph->vertices['J' - 'A'], 1);
	add_edge_undirected(my_graph->vertices['G' - 'A'], my_graph->vertices['K' - 'A'], 2);
	add_edge_undirected(my_graph->vertices['G' - 'A'], my_graph->vertices['L' - 'A'], 3);
	add_edge_undirected(my_graph->vertices['I' - 'A'], my_graph->vertices['K' - 'A'], 11);
	add_edge_undirected(my_graph->vertices['J' - 'A'], my_graph->vertices['L' - 'A'], 5);

	printf("DFS from A: "); 
	if (!dfs(my_graph, 'A', 'X')) 
	{
		printf("\n Character Not found \n");
	}
	reset_graph(my_graph);

	printf("DFS from K: "); 
	if (!dfs(my_graph, 'K', 'B')) 
	{
		printf("\n Character Not found \n");
	}
	reset_graph(my_graph);
	
	return 0;
}
