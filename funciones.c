/**********************************
* Fecha: 25/07/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Entrada y Salida en C
***********************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "funciones.h"



/*sumar dos valores que entran por teclado*/
void suma(){
  int a,b;
  printf("Ingrese el primer valor: ");
  scanf("%d",&a);
  printf("Ingrese el segundo valor: ");
  scanf("%d",&b);
  
  int suma = a + b;
  
  printf("La suma de %d + %d = %d\n", a,b,suma);
}
  
  /*calcular area de circulo ingresando por teclado el radio*/
void areaCirculo(){
  int radio;
  printf("Ingrese el valor del radio: ");
  scanf("%d",&radio);
    
  float area = radio*radio*3.1416;
  
  printf("El valor del area de un circulo de radio %d es: %f\n", radio,area);
}
  /*calclar volumen de la circunferencia  ingresando por teclado el radio*/
void volumenCircunferencia(){
  int radio;
  printf("Ingrese el valor del radio: ");
  scanf("%d",&radio);
    
  float volumen = radio*radio*radio*(4/3)*3.1416;
  
  printf("El valor del volumen de una circunferencia de radio %d es: %f\n", radio,volumen);
}
  /*calcular el volumen de un cono ingreando por teclado las variables necesarias*/
void volumenCono(){
  int radio, altura;
  printf("Ingrese el valor del radio de la base: ");
  scanf("%d",&radio);
  printf("Ingrese el valor de la altura del cono: ");
  scanf("%d",&altura);
    
  float volumen = (radio*radio*3.14)/3;
  
  printf("El valor del volumen del cono de radio %d y altra %d es : %f\n", radio,altura,volumen);
}
  /*calcular la tangente de un angulo ingresando los dos catetos del triandgulo*/
void tangente(){
  int opuesto, adyacente;
  printf("Ingrese el valor del cateto opuesto: ");
  scanf("%d",&opuesto);
  printf("Ingrese el valor del cateto adyacente");
  scanf("%d",&adyacente);
  
  float tangente = opuesto/adyacente;
  
  printf("El valor de la tangente de un angulo con catetos %d, %d es: %f\n", opuesto,adyacente,tangente);
}
  /*calcular la hipotenusa de un triangulo ingresando los dos catetos del triandgulo*/
void hipotenusa(){
  int opuesto, adyacente;
  printf("Ingrese el valor del cateto opuesto: ");
  scanf("%d",&opuesto);
  printf("Ingrese el valor del cateto adyacente");
  scanf("%d",&adyacente);
  
  float hipotenusa = sqrt((opuesto*opuesto)+(adyacente*adyacente));
  
  printf("El valor de la hipotenusa de un triangulo con catetos %d, %d es: %f\n", opuesto,adyacente,hipotenusa);
}
