#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    queue * q = create_queue();
    // perform operations
    return 0;
}

