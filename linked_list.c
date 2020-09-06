#include <stdlib.h>

struct linked_list
{
    struct node *first_node;
};

struct node
{
    int value;
    struct node *next_node;
};

struct linked_list *create_linked_list()
{
    struct linked_list *linked_list = (struct linked_list *)malloc(sizeof(struct linked_list));
    linked_list->first_node = (struct node *)malloc(sizeof(struct node));

    return linked_list;
}

struct node *create_node(int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;

    return new_node;
}

void insert_node()
{
}

void insert_beginning_node(struct linked_list *linked_list, struct node *new_node)
{
    new_node->next_node = linked_list->first_node;

    linked_list->first_node = new_node;
}

void print_linked_list(struct linked_list *linked_list)
{
    struct node *current_node = linked_list->first_node;
    
    while (!current_node)
    {
        printf(current_node->value);

        current_node = current_node->next_node;
    }
}