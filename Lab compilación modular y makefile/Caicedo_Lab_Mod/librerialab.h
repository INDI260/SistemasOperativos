/***************************************************************
* Fecha: 29/08/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Laboratorio compilación modular
*       - Funcionamiento del código
        - Modularización del código
        - Creación de fichero de Automatización de Compilación
****************************************************************
    INTERFAZ DE LIBRERIA DE FUNCIONES: MENÚ DE FUNCIONES
****************************************************************/

#ifndef _LIBRERIALAB_H_
#define _LIBRERIALAB_H_

#define CAPACIDAD_INICIAL 4

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

/*Incicialización de los valores del Vector, casting y reserva de memoria*/
void vectorInicio(vectorDinamico *V);

/*Retorna el total de elementos*/
int totalVector(vectorDinamico *V);

/*Redimensiona el vector*/
static void resizeVector(vectorDinamico *V, int capacidad);

/*Agregar elementos al vector*/
void addVector(vectorDinamico *V, void *elemento);

/*Liberación de Memoria Dinámica*/
void freeVector(vectorDinamico *V);

/*Obtención de elemento seún indice*/
void *getVector(vectorDinamico *V, int indice);

/*Ubicar un elemento en un indice i*/
void setVector(vectorDinamico *V, int indice, void *elemento);

/*Borra elemento según indice, redimensión de ser necesario*/
void borrarVector(vectorDinamico *V, int indice);

#endif