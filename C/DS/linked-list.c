#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node
{
    int value;
    struct list_node * next;
};
typedef struct list_node list_node;

struct list
{   
    list_node * head;
    int size;
};
typedef struct list list;

list * create_list()
{
    list * l = (list *) malloc(sizeof(list));
    l->head = NULL;
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
    ln->next = l->head;
    l->head = ln;
    l->size++;
}

void push_back_list(list * l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = NULL;
    list_node * temp = l->head;
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        l->head = ln;
    }
    else
    {
        temp->next = ln;
    }
    l->size++;
}

int pop_list(list * l)
{
    if (empty_list(l))
    {
        printf("Oops! List already empty!");
        return 0;
    }
    
    int value = l->head->value;
    list_node * ln = l->head;
    l->head = l->head->next;
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
    if (l->size == 1)
    {
        int value = l->head->value;
        free(l->head);
        l->head = NULL;
        l->size--;
        return value;
    }
    list_node * ln = l->head;
    while (ln->next->next != NULL)
    {
        ln = ln->next;
    }
    int value = ln->next->value;
    free(ln->next);
    ln->next = 0;
    l->size--;
    return value;    
}

int main()
{
    list * l = create_list();
    // perform operations
    return 0;
}
