#include <stdio.h>
#include <stdlib.h>

/*
-->Problem Description:
    - You are given an integer num.
    - You can swap two digits at most once to get the maximum valued number.

    - Return the maximum valued number you can get.
*/

int maximumSwap(int num);

int main()
{
    int x = 99739;
    int y = maximumSwap(x);
    printf("result = %i", y);

    return 0;
}

int maximumSwap(int num) {
    int result = num;
    int temp = num;
    int size = 0;
    while(temp>0){
        size++;
        temp /= 10;
    }
    temp = num;
    char str[size+1];
    for(int i = size-1; i >= 0; i--){
        str[i] = (temp%10) + '0';
        temp /= 10;
    }

    str[size] = '\0';

    for(int j = 0; j < size - 1; j++){
        int max = str[j];
        int index = j;
        for(int i = j+1; i < size; i++){
            if(str[i] >= max){
                max = str[i];
                index = i;
            }
        }

        if(max != str[j]){
            str[index] = str[j];
            str[j] = max;
            break;
        }
    }
    result = atoi(str);
    return result;
}
