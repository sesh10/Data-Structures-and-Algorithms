#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NIL -1
#define INFINITY 100000000

struct edge
{
    int vertex;
    int weight;
};
typedef struct edge edge;

edge create_edge(int vertex, int weight)
{
    edge e;
    e.vertex = vertex;
    e.weight = weight;
    return e;
}

struct heap
{
    edge * arr;
    int size;
};
typedef struct heap heap;

heap * create_heap(int max_size)
{
    heap * h = (heap *) malloc(sizeof(heap));
    h->arr = (edge *) malloc(sizeof(edge) * max_size);
    h->size = 0;
    for (int i = 0; i < max_size; i++)
    {
        h->arr[i].vertex = 0;
        h->arr[i].weight = 0;
    }
    return h;
}

bool empty_heap(heap * h)
{
    return h->size == 0;
}

void swap(edge * num1, edge * num2)
{
    edge temp = * num1;
    * num1 = * num2;
    * num2 = temp;
}

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int min(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

void insert_max_heap(heap * h, edge value)
{
    h->arr[++h->size] = value;
    int child = h->size;
    while (child > 1 && h->arr[child].weight > h->arr[child/2].weight)
    {
        swap(&h->arr[child], &h->arr[child/2]);
    }
}

void insert_min_heap(heap * h, edge value)
{
    h->arr[++h->size] = value;
    int child = h->size;
    while (child > 1 && h->arr[child].weight < h->arr[child/2].weight)
    {
        swap(&h->arr[child], &h->arr[child/2]);
    }
}

edge extract_max_heap(heap * h)
{
    edge e = {0, 0};
    if (empty_heap(h))
    {
        printf("Error! Heap is full");
        return e;
    }
    edge value = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size--;
    int parent = 1;
    int left_child, right_child;
    do
    {
        left_child = parent * 2;
        right_child = (parent * 2) + 1;
        if (h->arr[parent].weight > max(h->arr[left_child].weight, h->arr[right_child].weight))
        {
            break;
        }
        if (h->size == left_child || h->arr[left_child].weight > h->arr[right_child].weight)
        {
            swap(&h->arr[left_child], &h->arr[parent]);
            parent = left_child;
        }
        else
        {
            swap(&h->arr[right_child], &h->arr[parent]);
            parent = right_child;
        }
    } while (parent < h->size);
    return value;
}

edge extract_min_heap(heap * h)
{
    edge e = {0, 0};
    if (empty_heap(h))
    {
        printf("Error! Heap is full");
        return e;
    }
    edge value = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size--;
    int parent = 1;
    int left_child, right_child;
    do
    {
        left_child = parent * 2;
        right_child = (parent * 2) + 1;
        if (h->arr[parent].weight < min(h->arr[left_child].weight, h->arr[right_child].weight))
        {
            break;
        }
        if (h->size == left_child || h->arr[left_child].weight < h->arr[right_child].weight)
        {
            swap(&h->arr[left_child], &h->arr[parent]);
            parent = left_child;
        }
        else
        {
            swap(&h->arr[right_child], &h->arr[parent]);
            parent = right_child;
        }
    } while (parent < h->size);
    return value;
}

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
    g->edges = (graph * *) malloc(sizeof(graph) * num_node);
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
        return;
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

void dijkstras(graph * g, int source, int destination)
{
    heap * h = create_heap(g->num_edges);
    int parents[g->num_node];
    int distances[g->num_node];
    for (int node = 0; node < g->num_node; node++)
    {
        parents[node] = NIL;
        distances[node] = INFINITY;
    }
    edge u = create_edge(source, 0);
    insert_min_heap(h, u);
    distances[source] = 0;
    parents[source] = NIL;
    while (!empty_heap(h))
    {
        u = extract_min_heap(h);
        edge_node * en = g->edges[u.vertex];
        while (en != NULL)
        {
            if (distances[u.vertex] + en->weight < distances[en->n])
            {
                distances[en->n] = distances[u.vertex] + en->weight;
                parents[en->n] = u.vertex;
                insert_min_heap(h, create_edge(en->n, distances[en->n]));
            }
            en = en->next;
        }
    }

    int path[g->num_node];
    int path_size = 0;
    int dest = destination;
    do
    {
        path[path_size++] = dest;
        dest = parents[dest];
    } while (dest != NIL);
    printf("Distance from %d to %d is: %d\n", source, destination, distances[destination]);
    for (int i = path_size-1; i >= 0; i--)
    {
        printf("%d ", path[i]);
    }
}


int main()
{
    int nodes, edges, source, dest;
    printf("hi\n");
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter source: ");
    scanf("%d", &source);
    printf("Enter destination: ");
    scanf("%d", &dest);
    printf("\n");

    graph * g = create_graph(nodes+1, false);
    while (edges--)
    {
        int u, v, weight;
        printf("Enter start node: ");
        scanf("%d", &u);
        printf("Enter end node: ");
        scanf("%d", &v);
        printf("Enter weight: ");
        scanf("%d", &weight);
        printf("\n");
        add_graph_edge(g, u, v, weight);
    }

    dijkstras(g, source, dest);
    return 0;
}
