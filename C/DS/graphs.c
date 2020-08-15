#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct edge_node
{
    int n;
    int weight;
    struct edge_node * next;
};
typedef struct edge_node edge_node;

struct graph
{
    edge_node * * edges;
    int num_node;
    int num_edges;
    bool is_dir;
};
typedef struct graph graph;

graph * create_graph(int num_node, bool is_dir)
{
    graph * g = (graph *) malloc(sizeof(graph));
    g->num_node = num_node;
    g->edges = 0;
    g->is_dir = is_dir;
    g->edges = (graph * *) malloc(sizeof(graph *) * num_node);
    int i;
    for (i = 0; i < g->num_node; i++)
    {
        g->edges[i] = NULL;
    }
    return g;
}

void print_graph(graph * g)
{
    int i;
    for (i = 0; i < g->num_node; i++)
    {
        printf("%d --> ", i);
        edge_node * en = g->edges[i];
        while(en)
        {
            printf("%d\t", en->n);
            en = en->next;
        }
        printf("\n");
    }
}

void add_graph_edge(graph * g, int u, int v, int weight)
{
    if (u > g->num_node || v > g->num_node)
    {
        printf("Node does not exist\n");
        return 0;
    }
    else
    {
        edge_node * e = (edge_node *) malloc(sizeof(edge_node));
        e->n = v;
        e->weight = weight;
        e->next = g->edges[u];
        g->edges[u] = e;
        if (!g->is_dir)
        {
            e = (edge_node *) malloc(sizeof(edge_node));
            e->n = u;
            e->weight = weight; 
            e->next = g->edges[v];
            g->edges[v] = e;
        }
        
        g->num_edges++;
    }
}

int main()
{
    graph * g = create_graph(3, false);
    
    // perform operations
    return 0;
}
