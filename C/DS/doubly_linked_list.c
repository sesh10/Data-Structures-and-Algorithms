#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node
{
    int value;
    struct list_node * next;
    struct list_node * prev;
};
typedef struct list_node list_node;

struct list
{   
    list_node * head;
    list_node * tail;
    int size;
};
typedef struct list list;

list * create_list()
{
    list * l = (list *) malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

bool empty_list(list * l)
{
    return l->size == 0;
}

void push_front_list(list * l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = ln->prev = NULL;
    if (empty_list(l))
    {
        l->head = l->tail = ln;
        l->size++;
        return 0;
    }
    ln->next = l->head;
    l->head->prev = ln;
    l->head = ln;
    l->size++;
}

void push_back_list(list * l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = ln->prev = NULL;
    if (empty_list(l))
    {
        l->head = l->tail = ln;
        l->size++;
        return 0;
    }
    ln->prev = l->head;
    l->tail->next = ln;
    l->tail = ln;
    l->size++;
}

int pop_front_list(list * l)
{
    if (empty_list(l))
    {
        printf("Oops! List already empty!");
        return 0;
    }
    int value = l->head->value;
    list_node * ln = l->head;
    if (l->size == 1)
    {
        l->size--;
        free(l->head);
        l->head = l->tail = NULL;
        return value;        
    }
    
    l->head = l->head->next;
    l->head->prev = NULL;
    free(ln);
    l->size--;
    return value;
}

int pop_back_list(list * l)
{
    if (empty_list(l))
    {
        printf("Oops! list already empty!");
        return 0;
    }
    int value = l->tail->value;
    if (l->size == 1)
    {
        free(l->tail);
        l->head = l->tail = NULL;
        l->size--;
        return value;
    }
    list_node * ln = l->tail;
    l->tail = l->tail->prev;
    l->tail->next = NULL;
    free(ln);
    l->size--;
    return value;    
}

int main()
{
    list * l = create_list();
    // preform operations
    return 0;
}
