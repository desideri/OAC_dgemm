

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
int max = 62;//numero de elementos de lsa matrix
double B[32][32], C[32][32];
double A[32][32];
clock_t t_ini, t_fin;
double secs;

int main(int argc, char** argv) {
    printf("********************\n");
    printf("**ALGORITMO DGEMM***\n\n");
	crear_aleatorios();
	
	t_ini = clock();//tiempo inicio
	dgemm();
	t_fin = clock(); //tiempo fin de clock
    
    int i,j;
   printf("********  C RESULTADO  *********\n");
    for(i=0;i!=32;i=i+1){
             for(j=0;j!=32;j=j+1){ 
            
                 printf("%g\t",C[i][j]);
                }
            printf("\n");
           }
			


	printf("\n");
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	printf("%.16g Tiempo total en milisegundos\n", secs * 100.0);
	printf("%.16g ini\n", (double)t_ini* 100.0);
	printf("%.16g fin\n", (double)t_fin* 100.0);

	getch();
    return (EXIT_SUCCESS);
}

void crear_aleatorios(){
     int numero= 9;
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
	//t_ini = clock();//tiempo inicio
    int i, j,k;
        for(i=0;i!=32;i=i+1){
        for(j=0;j!=32;j=j+1){
        for(k=0;k!=32;k=k+1){
          C[i][j]=C[i][j]+A[i][k]*B[k][j];
        }}}

		/*
		t_fin = clock(); //tiempo fin de clock

		secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
		printf("%.16g milisegundos\n", secs * 1000.0);
		printf("%.16g ini\n", (double)t_ini* 1000.0);
		printf("%.16g fin\n", (double)t_fin* 1000.0);*/
}

/* retorna "a - b" en segundos */



