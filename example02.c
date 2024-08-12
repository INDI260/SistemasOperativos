/**********************************
* Fecha: 08/08/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Puntero a punteros
***********************************/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  
  int var = 480;
  int *varptr = &var;
  int **doubleptr = &varptr;
  
  printf("Valor de la Variable \t\t= %d\n", var);
  printf("valor del puntero    \t\t= %d\n", *varptr);
  printf("Valor del puntero doble \t= %d\n", **doubleptr);
  
  printf("Dirección de la Variable \t= %p\n", &var);
  
  printf("DireccIón del puntero \t\t= %p\n", &varptr);
  printf("Valor en el puntero \t\t= %p\n", varptr);
  
  printf("Valor del puntero doble \t= %p\n", *doubleptr);
  printf("Valor en el puntero doble \t= %p\n", doubleptr);
  
  return 0;
}