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
/*void dgemm(double A[][], double B[][], double C[][]);
*/
 double B[32][32], C[32][32];
int x;

int main(int argc, char** argv) {
  
   
     crear_aleatorios();
     x=5;
    printf("%d",x);

 
    return 0;
}

void crear_aleatorios(){
     int numero= 32;
      double A[32][32];
     int num;
     int i,j;
     
    srand(time(NULL));
    for(i=0;i!=32;i=i+1){
     for(j=0;j!=32;j=j+1){ 
         num = rand()%10; 
         A[i][j]=num;
        
        // printf("%d",A[i][j]);
         printf("%.2f",A[i][j]);
        }
    printf("\n");
   }
    
}
/*
void dgemm(double A[][], double B[][], double C[][]){
    int i, j,k;
    for(i=0;i!=32;i=i+1){
    for(j=0;j!=32;j=j+1){
    for(k=0;k!=32;k=k+1){
      c[i][j]=c[i][j]+a[i][k] * b[k][j];
}}}
}*/


