/**********************************
* Fecha: 08/08/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Asignación de Memoria Dinámica
*       Asignación de tamaño en Bytes de almacenamiento
***********************************/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  
  int *varptr1 = malloc(4*sizeof(int));     //Asignación suficiente para un vector entero de size 4
  int *varptr2 = malloc(sizeof(int[4]));    //Asignación suficiente para un vector entero de size 4
  int *varptr3 = malloc(4*sizeof *varptr3); //Asignación sufientente para un vector entero de size 4
  
  /*Impresión del vector varptr1*/
  if(varptr1){
    for(int i = 0; i < 4; i++)
      varptr1[i] = i*i;
    for(int i = 0; i < 4; i++)
      printf("varptr1[%d]\t == %d\n", i,  varptr1[i]);
  }

  printf("Se libera la memoria reservada\n");

  /*Liberación de memoria*/
  free(varptr1);
  free(varptr2);
  free(varptr3);


  return 0;
}
