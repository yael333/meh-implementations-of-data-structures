#include<stdlib.h>

struct Queue {
    int* array;
    unsigned int capacity; 
    int front, back, size;
};

struct Queue* create_queue(unsigned int capacity) 
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));

    queue->array = (int*) malloc(sizeof(int) * capacity); 
    queue->capacity = capacity;
    queue->size = 0;

    queue->front = 0;
    queue->back = capacity - 1;

    return queue;
}

int is_full(struct Queue *queue)
{
    return queue->size == queue->capacity;
}

int is_empty(struct Queue *queue) 
{
    return queue->size == 0;
}

int peek_front(struct Queue *queue)
{
    return queue->array[ queue->front ];
}

int peek_back(struct Queue *queue)
{
    return queue->array[ queue->back ];
}

void enqueue(struct Queue *queue, int n) 
{
    if (is_full(queue))
    {
        return;
    }
    queue->size++;

    queue->back = (queue->back + 1) % queue->capacity;
    queue->array[ queue->back ] = n;
}

int dequeue(struct Queue *queue)
{
    if (is_empty(queue))
    {
        return -1;
    }
    int element = queue->array[ queue->front ];
    queue->size--;

    queue->front = (queue->front+1) % queue->capacity;
    return element;
}
