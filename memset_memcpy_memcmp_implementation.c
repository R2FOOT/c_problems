#include <stdio.h>
#include <stdlib.h>

char arr [30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,
                          22,23,24,25,26,27,28,29,30};
char destination [30];


void *memset_f(void *start, int value, size_t length);
void *memcpy_f(void *dest, const void * src, size_t n);
int memcmp(const void *mem1, const void *mem2, size_t n);


int main()
{
    void *start_ptr = NULL;
    void *destination_ptr = NULL;
    int cmp_state1 = 0, cmp_state2 = 0, cmp_state3 = 0;

    start_ptr = memset_f(arr, '*', 7);                  /// The ASCI CODE of '*' is 42

    destination_ptr = memcpy_f(destination, arr, 20);

    cmp_state1 = memcmp(destination, arr, 25);
    cmp_state2 = memcmp(arr, destination, 15);
    cmp_state3 = memcmp(arr, destination, 25);


    for(unsigned short i = 0; i<30; i++){
        printf("%i\n", *(destination+i));
    }

    printf("--------------------------------------\n");

    printf("Comparison State 1: %i\n",cmp_state1);
    printf("Comparison State 2: %i\n",cmp_state2);
    printf("Comparison State 3: %i\n",cmp_state3);


    return 0;
}

void *memset_f(void *start, int value, size_t length){
    if(NULL == start){
        printf("INVALID POINTER IS USED!");
    }else{
        for(unsigned short counter=0; counter < length; counter++){
            *((char*)start + counter) = value;
        }
    }
    return start;
}

void *memcpy_f(void *dest, const void * src, size_t n){
    if((NULL == dest) || (NULL == src)){
        printf("INVALID POINTER IS USED!");
    }else{
        while(n--){
            *((char*)dest++) = *((char*)src++);
        }
    }
    return dest;
}

int memcmp(const void *mem1, const void *mem2, size_t n){
    int cmp = 0;
    if((NULL == mem1) || (NULL == mem2)){
        printf("INVALID POINTER IS USED!");
    }else{
        while(n--){
        if((*((char*)mem1++) == *((char*)mem2++))){
            cmp = 0;
        }else{
            cmp = (*((char*)mem1++) > *((char*)mem2++)) ? 1 : -1;
            break;
            }
        }
    }
    return cmp;
}
