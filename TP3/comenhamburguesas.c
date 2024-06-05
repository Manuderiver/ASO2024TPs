#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_THREADS 2
#define CANTIDAD_INICIAL_HAMBURGUESAS 20
int cantidad_restante_hamburguesas = CANTIDAD_INICIAL_HAMBURGUESAS;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int turno = 0;

void *comer_hamburguesa(void *tid)
{
    long int thread_id = (long int)tid;
    while (1 == 1)
    {
        pthread_mutex_lock(&mutex);
        while (turno != (int)thread_id) 
        {
            pthread_cond_wait(&cond, &mutex);
        }
if (cantidad_restante_hamburguesas > 0)
{
    printf("Hilo(comensal) %ld se come una hamburguesa. Quedan %d hamburguesas.\n", thread_id, cantidad_restante_hamburguesas);
    cantidad_restante_hamburguesas--;
    turno = (turno + 1) % NUMBER_OF_THREADS;
    pthread_cond_signal(&cond); 
} 
    else 
    {
        printf("SE TERMINARON LAS HAMBURGUESAS :(\n");
        
        pthread_mutex_unlock(&mutex);
        pthread_exit(NULL);
    }
    pthread_mutex_unlock(&mutex);
    } 
    return NULL;
}
int main(int argc, char *argv[])
{ 
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i, ret;
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    { 
        printf("Hola!, soy el hilo principal. Estoy creando el hilo %d \n", i);
        status = pthread_create(&threads[i], NULL, comer_hamburguesa, (void *)(long int)i);
        if (status != 0) 
        {
            printf("Algo salio mal, al crear el hilo recibi el codigo de error %d \n", status);
            exit(-1);
        }
    }

    for (i = 0; i < NUMBER_OF_THREADS; i++) 
    {
        void *retval;
        ret = pthread_join(threads[i], &retval); 
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    pthread_exit(NULL); 
} 
