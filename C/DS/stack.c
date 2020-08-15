#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack_node
{
    int value;
    struct stack_node * next;
};
typedef struct stack_node stack_node;

struct stack
{
    stack_node * top;
    int size;
};
typedef struct stack stack;

stack * create_stack()
{
    stack * s = (stack *) malloc(sizeof(stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

bool empty_stack(stack * s)
{
    return s->size == 0;
}

void push_stack(stack * s, int value)
{
    stack_node * n = (stack_node *) malloc(sizeof(stack_node));
    n->value = value;
    n->next = s->top;
    s->top = n;
    s->size++;
}

int pop_stack(stack * s)
{
    int value = s->top->value;
    stack_node * sn = s->top;
    s->top = s->top->next;
    s->size--;
    free(sn);
    return value;
}

int main()
{
    stack * s = create_stack();
    // perform operations
    return 0;
}

