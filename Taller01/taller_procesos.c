/**********************************
* Fecha: 17/10/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Taller1
* Tópico: Uso de fork, named pipe, archivos en un ejercicio práctico
***********************************/

/*Este fichero contiene un programa que lee numeros de dos archivos de texto que recibe como parametros, y los procesa de manera paralela usando forks que se comunican a través de una named pipe*/

#include <stdio.h>//Biblioteca de funciones básicas de c
#include <stdlib.h>//Bibliotecas adicionales de puntetos, estructuras de datos, contenedores, etc...
#include <unistd.h>//Biblioteca de comunicación con sistema de unix
#include <sys/types.h>//Interfaces con todo tipo de sistemas
#include <sys/stat.h>
#include <fcntl.h>//Bibliotecas para el uso de pipes y lectura de archivos
#include <string.h>//Biblioteca para manejo de cadenas de caracteres

#define FIFO_FILE "FIFO"//Se define el nombre que llevara la fifo en la estructura de archivos

int* lecturaDeArchivos(char* nomArch, int tam){
  
  int *arr = calloc(tam, sizeof(int));;//Se crea un arreglo para almacenar los datos leidos

  FILE *fp = fopen(nomArch, "r");//Se abre el archivo en modo lectura

  if (fp == NULL){//Se verifican errores en la apertura de archivos
      printf("Error: no se pudo abir el archivo %s", nomArch);
  }
  
  const unsigned MAX_LENGTH = 256;//Se asigna un tamaño máximo para el buffer
  char buffer[MAX_LENGTH];//Se crea el buffer de lectura
  int cont = 0;//Se crea un contador para la asignación de valores al arreglo

  /*Se asignan uno a uno los valores leidos del archivo al arreglo de enteros*/
  while (fgets(buffer, MAX_LENGTH, fp)){
      arr[cont] = atoi(buffer);
      cont++;
  }
  
  fclose(fp);//Se cierra el flujo con el archivo
  return arr;//Se retorna el arreglo lleno
}

pid_t creacionFork(){
    pid_t proceso; //se crea una variable para guardar el retorno del fork
    proceso = fork();//Se hace fork al proceso y se guarda el process id
    if(proceso<0){
        printf("Error creación proceso\n");//Si es numero negativo significa error
        exit(1);
    }else
        return proceso;//Se retorna el id del proceso
}

/*Suma todos los enteros de un arreglo y retorna el valor*/
int sumaDeEnteros(int* arr, int tam){
  int suma = 0;
  
  for(int i = 0; i < tam; i++)
    suma += arr[i];
  
  return suma;
}

int main (int argc, char *argv[]){
  
  int fd;//Variable que guarda el file descriptor de la FIFO
  char readbuf[80];//Buffer para almacenar lo leido de la FIFO
  char end[10];//Cadena terminal
  int to_end;//Variable de bandera que determina si se ha recibido un mensaje terminal
  int read_bytes;//Variable que almacena el numero de bytes que se leen de la FIFO
  int proceso;//Variable que determina si un proceso es padre o hijo
  int suma;//Variable que almacena el valor de las sumas
  int tam1 = atoi(argv[1]);//Variable que almacena el tamaño del primer arreglo
  int tam2 = atoi(argv[3]);//Variable que almacena el tamaño del segundo arreglo
  
  /*Se llenan los dos arreglos con los números de los archivos*/
  int *arr1 = lecturaDeArchivos(argv[2], tam1);
  int *arr2 = lecturaDeArchivos(argv[4], tam2);
  
  mkfifo(FIFO_FILE, S_IFIFO|0640);//Se crea la FIFO con permisos de lectura escritura
  fd = open(FIFO_FILE, O_RDWR);//Se abre la FIFO en modo lectura escritura
  
  proceso = creacionFork();//Se realiza el primer fork
  
  /*Primer hijo*/
  if(proceso == 0){
    proceso = creacionFork();
    /*Grand hijo*/
    if(proceso == 0){
      suma = sumaDeEnteros(arr1, tam1);//Se realiza la suma
      printf("Grand hijo: la sumaA total del arreglo del fichero00 es: %d\n", suma);//Se imprime el resultado de la suma
      write(fd, &suma, sizeof(int));//Se envía el resultado por la FIFO
      return 1;//Se termina el proceso
    }
    /*Primer hijo*/
    if(proceso > 0){
      int sumaA, sumaB;
      read(fd, &sumaA, sizeof(int));
      read(fd, &sumaB, sizeof(int));//Se leen los dos resualtados enviados 
      suma = sumaA + sumaB;//Se reliza la suma de los dos resultados obtenidos
      printf("Primer hijo: la suma total desde los dos arreglos es: %d\n", suma);//Se imprime el resultado
      write(fd, &suma, sizeof(int));//Se envía el resultado por la FIFO
      return 2;//Se termina la ejecución
    }
  }
  
  /*Padre*/
  else{
    proceso = creacionFork();
    /*Segundo Hijo*/
    if(proceso == 0){//Se realiza proceso similar a grand hijo
      suma = sumaDeEnteros(arr2, tam2);
      printf("Segundo hijo: la sumaB total del arreglo del fichero01 es: %d\n", suma);
      write(fd, &suma, sizeof(int));
      return 3;
    }
    /*Padre*/
    else{
      sleep(2);//Se espera para darle tiempo a los demás procesos
      read(fd, &suma, sizeof(int));//Se lee el resultado final de la FIFO
      printf("Padre: la suma total calculada en el hijo es: %d\n", suma);//Se imprime el resultado final
    }
  }
  
  close(fd);//Se cierra la fifo
  
  /*Se libera memoria*/
  free(arr1);
  free(arr2);
   
  
  return 0;//Se termina la ejecución del programa
}