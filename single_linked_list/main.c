#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


int main()
{
    unsigned int number_of_nodes = 5;
    node* list_head = create_single_linked_list(number_of_nodes);

    int x = 10;
    add_data(list_head, &x, 1);
    char y = 'a';
    add_data(list_head, &y, 2);
    float z = 18.5;
    add_data(list_head, &z, 3);
    int a = 80;
    add_data(list_head, &a, 4);
    char b = 'k';
    add_data(list_head, &b, 5);

    int* retrieved_data = (int*)retrieve_data(list_head, 1);
    printf("%i\n", *retrieved_data);
    char* retrieved_data1 = (char*)retrieve_data(list_head, 2);
    printf("%c\n", *retrieved_data1);
    float* retrieved_data2 = (float*)retrieve_data(list_head, 3);
    printf("%f\n", *retrieved_data2);
    int* retrieved_data3 = (int*)retrieve_data(list_head, 4);
    printf("%i\n", *retrieved_data3);
    char* retrieved_data4 = (char*)retrieve_data(list_head, 5);
    printf("%c\n", *retrieved_data4);


    return 0;
}
