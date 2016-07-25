/* 
 * File:   main.c
 * Author: Kattya Desiderio
 *
 * Created on 22 de julio de 2016, 10:38
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 
 */

void crear_aleatorios();
void dgemm();
/*void dgemm(double A[][], double B[][], double C[][]);
*/
double B[32][32], C[32][32];
double A[32][32];

int main(int argc, char** argv) {
    printf("********************\n");
    printf("**ALGORITMO DGEMM***\n\n");
    crear_aleatorios();
    dgemm();
    int i,j;
    printf("********  C RESULTADO  *********\n");
    for(i=0;i!=32;i=i+1){
             for(j=0;j!=32;j=j+1){ 
                // printf("%d",A[i][j]);
                 printf("%g",C[i][j]);
                }
            printf("\n");
           }

    return (EXIT_SUCCESS);
}

void crear_aleatorios(){
     int numero= 32;
     
     int num;
     int i,j;
     
    srand(time(NULL));
    printf("********  A  *********\n");
    for(i=0;i!=32;i=i+1){
     for(j=0;j!=32;j=j+1){ 
         num = rand()%10; 
         A[i][j]=num; 
        // printf("%d",A[i][j]);
         printf("%g",A[i][j]);
        }
    printf("\n");
    }
     printf("********  B  *********\n");
    for(i=0;i!=32;i=i+1){
         for(j=0;j!=32;j=j+1){ 
             num = rand()%10; 
             B[i][j]=num; 
            // printf("%d",A[i][j]);
             printf("%g",B[i][j]);
            }
        printf("\n");
       }
    printf("********  C  *********\n");
    for(i=0;i!=32;i=i+1){
            for(j=0;j!=32;j=j+1){ 
                num = rand()%10; 
                C[i][j]=num; 
               // printf("%d",A[i][j]);
                printf("%g",C[i][j]);
               }
           printf("\n");
          }
    }


void dgemm(){
    int i, j,k;
        for(i=0;i!=32;i=i+1){
        for(j=0;j!=32;j=j+1){
        for(k=0;k!=32;k=k+1){
          C[i][j]=C[i][j]+A[i][k] * B[k][j];
        }}}
}


