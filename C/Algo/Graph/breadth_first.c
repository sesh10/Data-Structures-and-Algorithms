#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct queue_node
{
    int value;
    struct queue_node * next;
};
typedef struct queue_node queue_node;

struct queue
{
    queue_node * front;
    queue_node * back;
    int size;
};
typedef struct queue queue;

queue * create_queue()
{
    queue * q = (queue *) malloc(sizeof(queue));
    q->size = 0;
    q->front = NULL;
    q->back = NULL;
    return q;
}

bool empty_queue(queue * q)
{
    return q->size == 0;
}

void push_queue(queue * q, int value)
{
    queue_node * qn = (queue_node *) malloc(sizeof(queue_node));
    qn->next = NULL;
    qn->value = value;
    if (empty_queue(q))
    {
        q->back = q->front = qn;
    }
    else
    {
        q->back->next = qn;
        q->back = qn;
    }
    q->size++;    
}

int pop_queue(queue * q)
{
    if (empty_queue(q))
    {
        printf("Oops! Queue already empty!");
        return 0;
    }
    
    int value = q->front->value;
    queue_node * qn = q->front;
    if (q->size == 1)
    {
        q->front = q->back = NULL;
    }
    else
    {
        q->front = q->front->next;
    }
    q->size--;
    free(qn);
    return value;
}

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

void graph_bfs(graph * g, int u)
{
    bool visited[g->num_node];
    for (int i = 0; i < g->num_node; i++)
        visited[i] = false;
    
    visited[u] = true;
    queue * q = create_queue();
    push_queue(q, u);
    for (int j = 0; j < 13; j++)
    {
        if (!empty_queue(q))
        {
            while (!empty_queue(q))
            {
                int x = pop_queue(q);
                visited[x] = true;
                printf("%d ", x);
                edge_node * e = get_neighbours(g, x);
                while (e != NULL)
                {
                    if (!visited[e->n])
                    {
                        push_queue(q, e->n);
                        visited[e->n] = true;
                    }
                    e = e->next;
                }            
            }
        }
        else if (empty_queue(q) && !visited[j])
        {
            push_queue(q, j);
        }         
    }    
}

int main()
{
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

    graph_bfs(g, 0);
    return 0;
}
