#include <stdio.h>
#include <stdlib.h>

/* ************************************************************************************* */
/* Author: Matej Kuna aka Matok | http://matok.me.uk                                     */
/*                                                                                       */
/* Description:                                                                          */
/* Demonstration how float number are stored.                                            */
/*  - scanf float number (it's actully double)                                           */
/*  - print it in binary representation                                                  */
/*  - more info: https://en.wikipedia.org/wiki/Double-precision_floating-point_format    */ 
/*                                                                                       */ 
/* Compile: gcc -Wall -std=c99 realnumber.c -o realnumber                                */   
/*                                                                                       */
/* ************************************************************************************* */

/**
 * Print bits representation of value.
 */
void print_bits(void *a, size_t size);

int main()
{
   double number;
   
   printf("Gimme float number: ");
   scanf("%lf", &number);
   printf("\n");

   print_bits(&number, sizeof(number));
   printf("\n");

   return EXIT_SUCCESS;
}

void print_bits(void *address, size_t size)
{
   int i;
   int b;
   address += size-1;
   
   printf("Printing %zu bytes:\n", size);
   for (i = size-1; i >= 0; i--) {  
     for (b = 7; b >= 0; b--) {
        printf("%d", (*(char *)address & (1<<b))>>b);
     }
     
     address--;
   }
}