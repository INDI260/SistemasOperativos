/**********************************
* Fecha: 25/07/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Entrada y Salida en C
***********************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "funcines.h"

int main(int argc, char *argv[]) {
  
  int opcion;
  while(true)  {
 
    printf("\n**********************************\nMENU\n**********************************\n\t1.Suma de dos numeros\n\t2.Area de un circulo\n\t3.Volumen de la circunferencia\n\t4.Volumen del cono\n\t5.Tangente en un triangulo\n\t6.Hipotenusa en un triangulo\n\t0.Cerrar el programa\n**********************************\n\nDigite la opción que desea: ");
    scanf("%d", &opcion);
  
    switch(opcion){
      case 0: return 0;break;
      case 1: suma();break;
      case 2: areaCirculo();break;
      case 3: volumenCircunferencia();break;
      case 4: volumenCono();break;
      case 5: tangente();break;
      case 6: hipotenusa();break;
      default: printf("Opcion no valida");
  }
}
  
  
  return 0;
}
