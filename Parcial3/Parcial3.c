/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Alejandro Caicedo
        Fecha: 7 de Noviembre de 2024
        Materia: Sistemas Operativos
        Tema: Parcial3
        Fichero: Cuenta de enteros
        Objetivo: Desarrollar una aplicación que permita crear una función que permita imprimir "Hilo ID iniciado"
****************************************************************/

/*Este fichero crea 5 hilos de los cuales cada uno cuenta hasta 300 e imprime sus ids y los primeros y ultimos numeros de la cuenta*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * contador() {
	printf("%ld inicado:\n", pthread_self());//Se imprime el mensaje de incio
	for( int i = 0;i < 300;i++) {//Se cuenta hasta 300
		if(i == 0 || i == 299)
			printf("\t%d\n", i);//Se imprime el primero y el ultimo numeros
	}
	printf("%ld terminado.\n", pthread_self());//Se imprime el mensaje final
}
int main() {

	pthread_t conHilo[5];//Se inicializan los identificadores de los hilos

	for(int i = 0; i < 5; i++)
		pthread_create(&conHilo[i], NULL, &contador, NULL);//Se crean los 5 hilos, cada uno que ejecuta la rutina contador

	for(int i = 0; i < 5; i++)
                pthread_join(conHilo[i], NULL);//Se espera a que termine la ejecución de todos los hilos
	return 0;
}
