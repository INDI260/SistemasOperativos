/**********************************
* Fecha: 03/10/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Manejo de hilos
* Tópico: Patron productor consumidor con posix
***********************************/

/*Este fichero contiene un ejemplo que introduce conceptos de uso de hilos paralelos, exclusividad mutua, variables condicionales y fundamentos del uso de la bilioteca pthread.
Este programa imprime una cuenta del 1 al 10 por consola usando los elementos anteriormente mencionados.
El comando de compilación debe ser este: gcc -g -pthread prod_cons_posix.c -o prod_cons_posix*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

int counter = 0;//Se define una variable global del contador
int max     = 4;//Se define una variable para el máximo 

/*Se inicializan los mutex con las constantes por defecto de la biblioteca*/
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condp_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condc_mutex = PTHREAD_MUTEX_INITIALIZER;
/*Se inicializan las condiciones con las constantes por defecto de la biblioteca*/
pthread_cond_t condVarProd = PTHREAD_COND_INITIALIZER;
pthread_cond_t condVarCons = PTHREAD_COND_INITIALIZER;

/*Se definen las rutinas complementarias*/
void *productor();
void *consumidor();

int main(){

        pthread_t proHilo[max], conHilo[max];//Se inicializan los identificadores de los hilos
        int i;//Se crea una variable de iteración
                for(i = 0; i < 5; i++) {
                        pthread_create(&proHilo[i], NULL, &productor, NULL);//Se crean 4 hilos que ejecutan e código de la rutina productor
                        pthread_create(&conHilo[i], NULL, &consumidor, NULL);//Se crean 4 hilos qeu ejecutan el código de la rutina consumidor
                }
                for(i = 0; i < 5; i++) {
                        pthread_join(proHilo[i], NULL);//Se espera a que se termine la ejecución de la rutina productor
                        pthread_join(conHilo[i], NULL);//Se espera a que se termine la ejecuicón de la rutina consumidor
                }

                return 0;//Se termina la ejecución del programa
}

void * productor(){
        while(1) {
                pthread_mutex_lock(&condp_mutex);//Se bloquea el mutex para eliminar condiciones de carrera
                while(counter >= 10) {
                        pthread_cond_wait(&condVarProd,&condp_mutex);//Se espera a que se cumpla la condición para terminar la rutina
                }
                pthread_mutex_unlock(&condp_mutex);//Se libera del mutex condicional

                pthread_mutex_lock(&counter_mutex);//Se bloquea el mutex del contador
                counter++;//Se aumenta el valor del contador
                pthread_cond_signal(&condVarCons);//Se espera a que se cumpla la condición
                printf("Soy productor %ld valor contador = %d\n", pthread_self(), counter);//Se imprime el valor del contador
                /*Se desbloquean los mutex al terminar de trabajar con los datos*/
                pthread_mutex_unlock(&condp_mutex);
                pthread_mutex_unlock(&counter_mutex);
                if(counter == 5)
                        sleep(1);//Si el contador es 5 se espera 1 segundo
        }
}

void * consumidor() {
        while(1) {
                sleep(1);//Se espera un segundo
        pthread_mutex_lock(&condc_mutex);//Se bloquea el mutex condeicional
        while(counter <= 0)
        {
                pthread_cond_signal(&condVarProd);//Se envía la señal de inicio
                pthread_cond_wait(&condVarCons, &condc_mutex);//Se espera a la señal terminal
        }
        /*Se desbloquean los mutex al terminar de trabajar con los datos*/
        pthread_mutex_unlock(&counter_mutex);

        pthread_mutex_lock(&counter_mutex);
        }
}