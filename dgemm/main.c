

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
 * PRIMERA OPCION CON LA FUNCION CLOCK
 */

    /*
    void crear_aleatorios();
    void dgemm();


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
    */
    /*
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
    */
   /*
    void dgemm(){
            //t_ini = clock();//tiempo inicio
        int i, j,k;
            for(i=0;i!=32;i=i+1){
            for(j=0;j!=32;j=j+1){
            for(k=0;k!=32;k=k+1){
              C[i][j]=C[i][j]+A[i][k]*B[k][j];
            }}}

    }
  */

    /*
     * SEGUNDA OPCION CON gettimeofday en MICROSEGUNDOS
     */


    #include <sys/time.h>

    void crear_aleatorios(int dimension);
    void dgemm(int dimension);
    double timeval_diff(struct timeval *a, struct timeval *b);
    int dimension = 960;
    
    double B[960][960];
    double C[960][960];
    double A[960][960];
    struct timeval t_ini, t_fin;
    double secs;


    int main(int argc, char** argv) {
        printf("\t\t\t\t**********************************\n");
        printf("\t\t\t\t          ALGORITMO DGEMM         \n\n");
        printf("\t\t\t\t**********************************\n\n");
     
        
        crear_aleatorios(dimension);

        gettimeofday(&t_ini, NULL);//tiempo inicio
        dgemm(dimension);
        gettimeofday(&t_fin, NULL); //tiempo fin de clock
        
        int i,j;
        printf("\t\t\t\t\t********  C*  *********\n\n");
        for(i=0;i!=dimension;i=i+1){
            for(j=0;j!=dimension;j=j+1){ 
                printf("\t\t%g\t",C[i][j]);
            }
            printf("\n\n");
        }

        printf("\n");
        secs = timeval_diff(&t_fin, &t_ini);
        printf("\t\t\t\t**********************************\n");
        printf("\t\t\t\t%.16g milliseconds\n", secs * 1000.0);
        printf("\t\t\t\t**********************************\n");
        
        //getch();
        return (EXIT_SUCCESS);
    }

    void crear_aleatorios(int max){
        int numero= 9;
        int num;
        int i,j;
        
        //srand(time(NULL));
        printf("\t\t\t\t\t********  A  *********\n\n");
        for(i=0;i!=max;i=i+1){
         for(j=0;j!=max;j=j+1){ 
             //num = rand()%10;
             num = 1;
             A[i][j]=num; 
            // printf("%d",A[i][j]);
             printf("\t\t%g\t",A[i][j]);
            }
        printf("\n\n");
        }
        printf("\t\t\t\t\t********  B  *********\n\n");
        for(i=0;i!=max;i=i+1){
             for(j=0;j!=max;j=j+1){ 
                 //num = rand()%10; 
                 num = 1;
                 B[i][j]=num; 
                // printf("%d",A[i][j]);
                 printf("\t\t%g\t",B[i][j]);
                }
            printf("\n\n");
           }
        printf("\t\t\t\t\t********  C  *********\n\n");
        for(i=0;i!=max;i=i+1){
                for(j=0;j!=max;j=j+1){ 
                    //num = rand()%10; 
                    num = 1;
                    C[i][j]=num; 
                   // printf("%d",A[i][j]);
                    printf("\t\t%g\t",C[i][j]);
                   }
               printf("\n\n");
              }
        }

    void dgemm(int max){
            //t_ini = clock();//tiempo inicio
        int i, j,k;
            for(i=0;i!=max;i=i+1){
            for(j=0;j!=max;j=j+1){
            for(k=0;k!=max;k=k+1){
              C[i][j]=C[i][j]+A[i][k]*B[k][j];
            }}}
    }

    // retorna "a - b" en segundos 
    double timeval_diff(struct timeval *a, struct timeval *b)
    {
      return
        (double)(a->tv_sec + (double)a->tv_usec/1000000) -
        (double)(b->tv_sec + (double)b->tv_usec/1000000);
    }
