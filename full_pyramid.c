/**
********************************************************************************
* @file       :   main.c
* @version    :   1.0.0
* @author     :   Ahmed Raafat Zidan
* @brief      :   create a Full Pyramid as a function of its steps (No.of rows)
********************************************************************************
*/

/* >>>>>>>>>>>>>>>>>>> Linking Section Start <<<<<<<<<<<<<<<<<<< */

#include <stdio.h>

/* >>>>>>>>>>>>>>>>>>>  Linking section End  <<<<<<<<<<<<<<<<<<< */


int main()
{
    unsigned char i,j,k,h;
    unsigned char stars_in_row = 0;
    unsigned char row;
    printf("Enter the number of stairs of the pyramid: ");
    scanf("%i", &j);
    unsigned char x[j];
    x[0] = j+1;
    for(k=1; k<=j-1; k++)
    {
        x[k] = x[k-1] + 2;
    }
    for(row=1; row<=j; row++)
    {
        for(i=1; i<=((2*j)-1); i++)
        {
            for(h= 0; h < sizeof(x) / sizeof(x[0]); h++)
            {
                if(x[h]==(i+row))
                {
                    printf("*");
                    stars_in_row++;
                    break;
                }
                else
                {
                    if(h==((sizeof(x) / sizeof(x[0]))-1))
                    {
                        printf(" ");
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            if(stars_in_row == row)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        stars_in_row = 0;
        printf("\n");
    }
    return 0;
}

/*
Example of the result (j = no.of rows = 5):
    *
   * *
  * * *
 * * * *
* * * * *

*/


/**
======================================================================
user                    Date                Brief
======================================================================
Ahmed Raafat Zidan      24/11/2023          Creation of the program

*/
