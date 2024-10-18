/**********************************
* Fecha: 03/10/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Fork de procesos
* Tópico: Creación de forks a partir de parametros de consola
***********************************/

#include <stdio.h>//Biblioteca de funciones básicas de c
#include <stdlib.h>//Bibliotecas adicionales de puntetos, estructuras de datos, contenedores, etc...
#include <unistd.h>//Biblioteca de comunicación con sistema de unix
#include <sys/types.h>//Interfaces con todo tipo de sistemas


void creacion_fork(int linea){
    pid_t proceso; //se crea una variable para guardar el retorno del fork
    proceso = fork();//Se hace fork al proceso y se guarda el process id
    if(proceso<0){
        printf("Error creación proceso\n");//Si es numero negativo significa error
        exit(1);
    }else if (proceso==0)
        printf("%d: Proceso =HIJO=: %d\n",linea, getpid());//Si es 0 es un porceso hijo
    else
        printf("%d: Proceso =PADRE= %d\n",linea, getpid());//Si es positivo es un proceso padre
}

int main(int argc, char *argv[]){
    int p = (int) atoi(argv[1]);//argumento de entrada por consola
    for(int i=0; i<p; i++)
        creacion_fork(i);//Se hacen p forks


    printf("\n---\n\n");
    return 0;
}