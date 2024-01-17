#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int func1(void);
unsigned int func2(void);
unsigned int func3(void);
unsigned int func4(void);

typedef unsigned int (*ptr)(void);

ptr functions[4] = {func1, func2, func3, func4};

ptr* return_functions(void);

int main(){

    ptr *func_ptr = return_functions();
    for(unsigned char i=0; i < 4; i++){
        printf("%i\n", (*(func_ptr++))());
    }

    return 0;
}

unsigned int func1(void){
    return 11;
}
unsigned int func2(void){
    return 22;
}
unsigned int func3(void){
    return 33;
}
unsigned int func4(void){
    return 44;
}

ptr* return_functions(void){
    return functions;
}
