#include <stdio.h>
#include <stdlib.h>

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize);

int main()
{
    int alice[3] = {8,3,11};
    int bob[3] = {5,2,9};
    int size = 0;
    int* swap_array = NULL;
    swap_array = fairCandySwap(alice, 3, bob, 3, &size);
    printf("[%i,%i]", *swap_array, *(swap_array+1));

    return 0;
}

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    int* indices_ptr = (int*) malloc(2*sizeof(int));
    int sumAlice = 0, sumBob = 0;
    int residue = 0;

    for(int j = 0; j < aliceSizesSize; j++){
        sumAlice += aliceSizes[j];
    }
    for(int k = 0; k < bobSizesSize; k++){
        sumBob += bobSizes[k];
    }
    residue = (sumBob - sumAlice)/2;
    printf("resid = %i\n", residue);
    for(int i = 0; i < aliceSizesSize; i++){
        for(int m = 0; m < bobSizesSize; m++){
            if (aliceSizes[i] + residue == bobSizes[m]) {
                indices_ptr[0] = aliceSizes[i];
                indices_ptr[1] = bobSizes[m];

                *returnSize = 2;

                return indices_ptr;
            }
        }
    }
    return NULL;
}

