#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct edge_node
{
    int n;
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

void add_graph_edge(graph * g, int u, int v)
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
        e->next = g->edges[u];
        g->edges[u] = e;
        if (!g->is_dir)
        {
            e = (edge_node *) malloc(sizeof(edge_node));
            e->n = u; 
            e->next = g->edges[v];
            g->edges[v] = e;
        }
        g->num_edges++;
    }
}

edge_node * get_neighbours(graph * g, int u)
{
    return g->edges[u];
}

void graph_dfs(graph * g, int u, bool visited[])
{
    if (visited[u])
        return;
    
    printf("%d ", u);
    visited[u] = true;
    edge_node * e = get_neighbours(g, u);
    while (e != NULL)
    {
        graph_dfs(g, e->n, visited);
        e = e->next;
    }
    
}

int main()
{
    int i;
    bool visited[13];
    for (i = 0; i < 13; i++)
        visited[i] = false;

    graph * g = create_graph(13, false);

    add_graph_edge(g, 0, 1);
    add_graph_edge(g, 1, 2);
    add_graph_edge(g, 1, 3);
    add_graph_edge(g, 2, 4);
    add_graph_edge(g, 2, 5);
    add_graph_edge(g, 3, 5);
    add_graph_edge(g, 3, 7);
    add_graph_edge(g, 4, 6);
    add_graph_edge(g, 5, 6);
    add_graph_edge(g, 6, 7);
    add_graph_edge(g, 8, 9);
    add_graph_edge(g, 9, 10);
    add_graph_edge(g, 10, 11);
    add_graph_edge(g, 11, 12);

    for (i = 0; i < 13; i++)
    {
        graph_dfs(g, i, visited);
    }
    
    return 0;
}
