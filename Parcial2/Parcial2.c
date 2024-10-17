/**********************************
* Fecha: 10/10/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Parcial 2
* Tópico: Aplicacione de los conceptos de procesos y comunicación entre processo
***********************************/

//fork: crea una copia de un proceso padre
//pipe: es un canal de comunicacion entre dos procesos

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO_FILE "FIFO"

int* lecturaDeArchivos(char* nomArch, int tam){
  
  int *arr = calloc(tam, sizeof(int));;//Se crea un arreglo para almacenar los datos leidos

  FILE *fp = fopen(nomArch, "r");

  if (fp == NULL){
      printf("Error: no se pudo abir el archivo %s", nomArch);
  }
  
  const unsigned MAX_LENGTH = 256;
  char buffer[MAX_LENGTH];
  int cont = 0;

  while (fgets(buffer, MAX_LENGTH, fp)){
      arr[cont] = atoi(buffer);
      cont++;
  }
  
  fclose(fp);
}

pid_t creacionFork(int linea){
    pid_t proceso; //se crea una variable para guardar el retorno del fork
    proceso = fork();//Se hace fork al proceso y se guarda el process id
    if(proceso<0){
        printf("Error creación proceso\n");//Si es numero negativo significa error
        exit(1);
    }else
        return proceso;
}

int sumaDeEnteros(int* arr, int tam){
  int suma = 0;
  
  for(int i = 0; i < tam; i++)
    suma += arr[i];
  
  return suma;
}

int main (int argc, char *argv[]){
  
  int fd;//Se crea variable para almacenar el dentificador del proceso
  char readbuf[10];//Se crea un buffer de 80 caracteres
  char end[10];//Se crea la variable par guardadar la cadena terminal
  int to_end;//Se define una variable para guardar la comparación
  int read_bytes;//Se define una validable para guardar el tamaño de los mesajes
  
  int *arr1 = lecturaDeArchivos(argv[2], atoi(argv[1]));
  int *arr2 = lecturaDeArchivos(argv[4], atoi(argv[3]));
  
  mknod(FIFO_FILE, S_IFIFO|0640, 0);
  
  for (int i = 0; i < 4; i++){
    if(creacionFork > 0){
      int suma = sumaDeEnteros(arr1, atoi(argv[1]));
      int fd = open(FIFO_FILE,O_WRONLY);
      write(fd, &suma, sizeof(suma));
      printf("GranHijo: %d Sum_File1 = %d",getpid(),suma);
      close(fd);
      free(arr1);
      exit(0);
    }
    
  }
    
  return 0;
}