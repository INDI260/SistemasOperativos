/**********************************
* Fecha: 15/08/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Gestión de memoria
* Tópico: Diferencias entre usar o no usar Punteros
***********************************/

#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(int *matriz, int n) { //Función que imprime matrices cuadradas
  for(int i = 0; i < (n*n); i++){
    if(i % n == 0)
      printf("\n");
    printf(" %d ", *(matriz+i));
  }
  printf("\n\n");
}

int main (){
  
  int n = 3;
  int mA[n*n];
  int mB[n*n];
  int mC[n*n];
  
  /*Inicialización*/
  for(int i = 0; i < (n*n); i++){
    mA[i] = 0;
    mB[i] = 2;
    mC[i] = 3;
  }
  
  /*Impresión*/
  for(int i = 0; i < (n*n); i++){
    if(i % n == 0)
      printf("\n");
    printf(" %d ", *(mA+i));
  }
  
  for(int i = 0; i < (n*n); i++){
    if(i % n == 0)
      printf("\n");
    printf(" %d ", *(mB+i));
  }
  printf("\n\n");
  
  for(int i = 0; i < (n*n); i++){
    if(i % n == 0)
      printf("\n");
    printf(" %d ", *(mC+i));
  }
  printf("\n\n");

  
  
  
  printf("\n\n\n... fin del programa\n");
  
  return 0;
}