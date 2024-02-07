#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


node* create_single_linked_list(unsigned int number_of_nodes){
    node* head = NULL;
    if(number_of_nodes > 0){
        head = (node*) malloc(sizeof(node));
        if(head == NULL){
            return NULL;
        }
        head->node_link = NULL;
        head->node_data_ptr = NULL;

        node* current = head;

        unsigned int nodes_counter = number_of_nodes - 1;
        while(nodes_counter--){
            current->node_link = (node*) malloc(sizeof(node));
            if(current->node_link == NULL){
                return NULL;
            }
            current = current->node_link;
            current->node_link = NULL;
            current->node_data_ptr = NULL;
        }

    }else{
        return NULL;
    }
    return head;
}

void add_data(node* list, void* data_ptr, unsigned int node_index){
    unsigned int node_counter = 1;
    node* current = list;
    while((node_counter != node_index) && (current != NULL)){
        current = current->node_link;
        node_counter++;
    }
    current->node_data_ptr = data_ptr;
}

void* retrieve_data(node* list, unsigned int node_index){
    unsigned int node_counter = 1;
    node* current = list;
    void* data_ptr = NULL;

    while((node_counter != node_index) && (current != NULL)){
        current = current->node_link;
        node_counter++;
    }
    if(current != NULL){
        data_ptr = current->node_data_ptr;
    }
    return data_ptr;
}


