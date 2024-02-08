#include <stdio.h>
#include <stdlib.h>

/*
-> Bubble sort and Insertion sort are both
1) simple sorting algorithms with quadratic time complexity O(n^2).
2) has adaptive Nature: time complexity is down to O(n) when data is already sorted.
-> Bubble sort can be used to find the biggest (#) numbers among data.
-> Selection Sort can be used to find the smallest (#) numbers among data.
-> Insertion sort is highly recommended with linked lists because
    it's not needed to make any shift.
*/

int* insertion_sort(int* array, unsigned int array_size);
int* bubble_sort(int* array, unsigned int array_size);
int* selection_sort(int* array, unsigned int array_size);

int main()
{
    int number[] = {3,6,1,8,4,5,8,1,-4,0};
    int *numbers = NULL;
    numbers = selection_sort(number, 10);
    for(unsigned int i = 0; i < 10; i++){
        printf("value in index (%i) = %i\n", i,numbers[i]);
    }
    printf("=================================\n");
    numbers = insertion_sort(number, 10);
    for(unsigned int i = 0; i < 10; i++){
        printf("value in index (%i) = %i\n", i,numbers[i]);
    }
    printf("=================================\n");
    numbers = bubble_sort(number, 10);
    for(unsigned int i = 0; i < 10; i++){
        printf("value in index (%i) = %i\n", i,numbers[i]);
    }
    return 0;
}

int* insertion_sort(int* array, unsigned int array_size){
    unsigned int back_index = 0;
    int key = 0;
    for(unsigned int i = 1; i < array_size; i++){
        back_index = i;
        key = array[i];
        while(back_index){
            if(key < array[back_index-1]){
                array[back_index] = array[back_index-1];
            }else{
                array[back_index] = key;
                break;
            }
            back_index--;
        }
        array[back_index] = key;
    }
    return array;
}

int* bubble_sort(int* array, unsigned int array_size){
    int temp = 0;
    int temp_size = array_size;
    while(temp_size--){
        for(unsigned int i = 0; i < temp_size; i++){
            if(array[i] > array[i+1]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    return array;
}

int* selection_sort(int* array, unsigned int array_size){

    for(unsigned int j = 0; j < array_size; j++){
        int smallest = array[j];
        int smallest_index = j;
        for(unsigned int i = j+1; i < array_size; i++){
            if(smallest > array[i]){
                smallest = array[i];
                smallest_index = i;
            }
        }
        array[smallest_index] = array[j];
        array[j] = smallest;
    }
    return array;
}
