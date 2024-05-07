#include <stdio.h>
#include <stdlib.h>


float y(float x);                               // function to integrate
float f(float x, float y);                      // ODE function to solve

void LU_decomposition(unsigned char n);

float trapzoidal_integration(float a, float b,
                             float n);          // uniform-spacing, n -> #of trapezoids
float simpson_integration(float a, float b,
                             float n);
float ODE_euler_method();


int main()
{
    unsigned char exit;
    unsigned char choice;
    unsigned char mat_dimension;
    float INT_lower_lim, INT_higher_lim;
    float n_steps;
    float result;

    printf("Choose one of the following to calculate: \n1) LU decomposition\n2) Trapezoidal integration\n3) Simpson integration\n4) ODE Euler method");
    start:
    printf("\nEnter your choice Number :");
    scanf("%i", &choice);
    if(choice == 1){
        printf("Enter the Matrix Dimension :");
        scanf("%i", &mat_dimension);
        LU_decomposition(mat_dimension);
    }else if (choice == 2){
        printf("Enter the integration lower and higher limits :");
        scanf("%f %f", &INT_lower_lim, &INT_higher_lim);
        printf("Enter the number of steps :");
        scanf("%f", &n_steps);
        result = trapzoidal_integration(INT_lower_lim, INT_higher_lim, n_steps);
        printf("The result of Trapezoidal Integration = %f", result);
    }else if (choice == 3){
        printf("Enter the integration lower and higher limits :");
        scanf("%f %f", &INT_lower_lim, &INT_higher_lim);
        printf("Enter the number of steps :");
        scanf("%f", &n_steps);
        result = simpson_integration(INT_lower_lim, INT_higher_lim, n_steps);
        printf("The result of Simpson Integration = %f", result);
    }else if (choice == 4){
        result = ODE_euler_method();
        printf("The result of Euler ODE = %f", result);
    }
    goto start;

    printf("Enter the exit code:\n");
    while(exit != 18){
        scanf("%i", &exit);
    }
    return 0;
}


void LU_decomposition(unsigned char n){
    float cof_arr[n][n];
    printf("Input elements in the matrix :\n");
    for (unsigned char row = 0; row < n; row++) {
        for (unsigned char col = 0; col < n; col++) {
            printf("Element - [%d],[%d] : ", row, col);
            scanf("%f", &cof_arr[row][col]);
        }
    }

    float lower[n][n];
    float upper[n][n];

    for(unsigned char row = 0; row < n; row++){
        for(unsigned char col = 0; col < n; col++){
            lower[row][col] = 0;
            upper[row][col] = 0;
        }
    }
    for(unsigned char i = 0; i < n; i++){
        lower[i][i] = 1;
    }

    for(unsigned char j = 0; j < n; j++){
        upper[0][j] = cof_arr[0][j];
    }
    for(unsigned char i = 1; i < n; i++){
        lower[i][0] = cof_arr[i][0] / upper[0][0];
    }


    for(unsigned char i = 1; i < n; i++){


        for(unsigned char j = i; j < n; j++){
            float sum = cof_arr[i][j];
            for(unsigned char count = 0; count < i; count++){    // < i-1
                sum -= lower[i][count] * upper[count][j];
            }
            upper[i][j] = sum;
        }



        for(unsigned char k = i+1; k < n; k++){
            float sum = cof_arr[k][i];
            for(unsigned char count = 0; count < i; count++){    // count < k-1
                sum -= lower[k][count] * upper[count][i];
            }
            lower[k][i] = sum/upper[i][i];
        }
    }

    /********** OUTPUT ***********/

    printf("The Lower Matrix: \n");
    for(unsigned char row = 0; row < n; row++){
        for(unsigned char col = 0; col < n; col++){
            printf("%.2f\t",lower[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    printf("The Upper Matrix: \n");
    for(unsigned char row = 0; row < n; row++){
        for(unsigned char col = 0; col < n; col++){
            printf("%.2f\t",upper[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    printf("The Coefficient Matrix:\n");
    for(unsigned char row = 0; row < n; row++){
        for(unsigned char col = 0; col < n; col++){
            printf("%.2f\t", cof_arr[row][col]);
        }
        printf("\n");
    }
}


float y(float x){
    return (1/(1+(x*x)));
}

float f(float x, float y){
    return ((3*x)+(x*y));
}

float trapzoidal_integration(float a, float b, float n){
    float step_size = (b-a)/n;
    float sum = (0.5)*(y(a)+y(b));
    for(int i=1; i<n; i++){
        sum += y(a+(i*step_size));
    }
    return sum*step_size;
}

float simpson_integration(float a, float b, float n){
    float step_size = (b-a)/n;
    float sum = y(a)+y(b);
    for(int i=1; i<n; i++){
        if(i%2 == 0){
            sum += (2 * y(a+(i*step_size)));
        }else{
            sum += (4 * y(a+(i*step_size)));
        }
    }
    return (sum*step_size/3);
}

float ODE_euler_method(){
    float x0 = 0, y0 = 0, steps = 0, xn = 0, yn=0;
    float step_size = 0;
    float slope = 0;
    printf("PLZ Enter the Initial condition: ");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter the point where to calculate the function value: ");
    scanf("%f", &xn);
    printf("Enter the number of steps: ");
    scanf("%f", &steps);
    step_size = (xn-x0)/steps;

    for(int i = 0; i <= steps; i++){
        slope = f(x0, y0);
        yn = y0 + step_size*slope;
        y0 = yn;
        x0 += step_size;
    }
    return yn;
}
