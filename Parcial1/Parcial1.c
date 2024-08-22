/**********************************
* Fecha: 22/08/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Parcial 1
*       Re-Asignación de tamaño de un vector dinámico en una estructura
***********************************/

/*Este programa permite el guardado y manejo de cadenas de caracteres en una estructura con asignación de memoria dinámica*/

#include <stdlib.h>
#include <stdio.h>
#define CAPACIDAD_INICIAL 4

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

/*Inicializa el Vector Dinámico*/
void vectorInicio(vectorDinamico *V){
        V->capacidad = CAPACIDAD_INICIAL;
        V->totalElementos = 0;
        V->elementos = malloc(sizeof(void *) * V->capacidad); 
}

/*Retorna el total de elementos del vector*/
int totalVector(vectorDinamico *V){
        return V->totalElementos;
}

/*Cambia el tamaño del vector de elementos usando la función realloc*/
static void resizeVector(vectorDinamico *V, int capacidad){
        printf("Redimensión: %d a %d \n\n\n", V->capacidad, capacidad);

        void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
        if(elementos){
                V->elementos = elementos;
                V->capacidad = capacidad;
        }
}

/*Añade un elemento al vector y aumenta su tamaño si hace falta*/
void addVector(vectorDinamico *V, void *elemento){
        if(V->capacidad == V->totalElementos)
                resizeVector(V, V->capacidad*2);
        V->elementos[V->totalElementos++] = elemento;
}

/*Libera la memoria asignada al vector Dinámico*/
void freeVector(vectorDinamico *V){
        free(V->elementos);
}

/*Retorna un elemento del vector de acuerdo con un indice dado*/
void *getVector(vectorDinamico *V, int indice){
        if(indice >= 0 && indice < V->totalElementos)
                return V->elementos[indice];
        return NULL;
}

/*Asigna un valor a un elemento del vector con un indice dado*/
void setVector(vectorDinamico *V, int indice, void *elemento){
        if(indice >= 0 && indice < V->totalElementos)
                V->elementos[indice]=elemento;
}

/*Asigna valor nulo un elemento del vector y reduce su capacidad de acuerdo a lo anterior*/
void borrarVector(vectorDinamico *V, int indice){
        if(indice < 0 || indice >= V->totalElementos)
                return; 

        V->elementos[indice] = NULL;

        for(int i=indice; i<V->totalElementos-1; i++){
                V->elementos[i] = V->elementos[i+1];
                V->elementos[i+1] = NULL; 
        }
        V->totalElementos--;
        if(V->totalElementos>0 && V->totalElementos == V->capacidad/4)
                resizeVector(V, V->capacidad/2);
}

int main(){
        vectorDinamico editor;//Se crea el vector Dinámico
        vectorInicio(&editor);//Se incializa el vector

        addVector(&editor, "Hola");
        addVector(&editor, "Profesional");
        addVector(&editor, "en");
        addVector(&editor, "Formación");
        addVector(&editor, "de");
        addVector(&editor, "Ingenieria\n");//Se añaden seis vectores de caracteres a los elementos

        for (int i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));//Se imprimen los elementos guardados en el vector
      
        printf("\n\n");
        
        for(int i = 5; i >= 2; i--)
        borrarVector(&editor, i);//Se elimina el primer elemento del vector

        setVector(&editor, 1, "Buenos");
        addVector(&editor,"Días");//Se reasigna el valor al primer y segundo elementos del vector


        for (int i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));//Se imprimen nuevamente los elementos
        printf("\n");
  
        freeVector(&editor); //Se libera la memoria asignada al vector
  
        return 0;//Se termina la ejecución del programa
}