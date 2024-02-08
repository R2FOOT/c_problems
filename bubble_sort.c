#include <stdio.h>
#include <stdlib.h>

int* bubble_sort(int* array, unsigned int array_size);

int main()
{
    int number[] = {5,1,1,2,0,0};
    int *numbers = NULL;
    numbers = bubble_sort(number, 6);
    for(unsigned int i = 0; i < 6; i++){
        printf("value in index (%i) = %i\n", i,numbers[i]);
    }
    return 0;
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
