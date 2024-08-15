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
  if(n < 6){
    for(int i = 0; i < (n*n); i++){
      if(i % n == 0)
        printf("\n");
      printf(" %d ", *(matriz+i));
    }
    printf("\n\n");
  }
}


int main (int argc, char *argv[]){
  
  if (argc < 2){//Checkea si hay un numero sufciciente de argumentos para ejecutar el programa
    printf("\nArgumentos válidos: $ejecutable sizeOfMatriz\n");
    exit(0);
  }
  int n = atoi(argv[1]);//Le asigna a n el valor del argumento dado por el usuario
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
  imprimirMatriz(mA, n);
  imprimirMatriz(mB, n);
  imprimirMatriz(mC, n);

  /*VERSION CLÁSICA MULTIPLICACION DE MATRICES: mA = mB*Mc*/
  
  int suma = 0;
  
  for(int i = 0; i < n; i++){//filas
    for( int j = 0;j < n; j++){//columnas
      for( int k = 0;k < n; k++){//filasXcolumnas
        suma += mB[(n*i)+k] * mC[(n*k)+j];
      }
      mA[j+(i*n)] = suma;
      suma = 0;
    }
  }

  imprimirMatriz(mA, n);
  
  
  printf("\n\n\n... fin del programa\n");
  
  return 0;
}