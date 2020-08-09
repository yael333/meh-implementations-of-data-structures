#include<stdlib.h>

struct Stack {
    int* array;
    int index;
    unsigned int size;
};

struct Stack* create_stack(unsigned int size) 
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

    stack->array = (int*) malloc(sizeof(int) * size); 
    stack->index = 0;
    stack->size = size;

    return stack;
}

int is_full(struct Stack *stack)
{
    return stack->index+1 == stack->size;
}

int is_empty(struct Stack *stack) 
{
    return stack->size - stack->index == 1;
}

int peek(struct Stack *stack)
{
    return stack->array[ stack->index ];
}

void push(struct Stack *stack, int n) 
{
    if (is_full(stack)) 
    {
        return ;
    }
    stack->array[++stack->index] = n;
}

int pop(struct Stack *stack)
{
    if (is_empty(stack))
    {
        return -1;
    }
    return stack->array[stack->index--];
}