#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdlib.h>

typedef struct node_ds{
    struct node_ds *node_link;
    void *node_data_ptr;
}node;

node* create_single_linked_list(unsigned int number_of_nodes);
void add_data(node* list, void* data_ptr, unsigned int node_index);
void* retrieve_data(node* list, unsigned int node_index);


#endif // _LINKED_LIST_H_
