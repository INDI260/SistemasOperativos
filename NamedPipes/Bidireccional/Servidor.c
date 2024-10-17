/**********************************
* Fecha: 17/10/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Named pipes Bidireccionales
* Tópico: Servidor de la named pipe
***********************************/

/*Este fichero contiene un programa que recibe una cadena de máximo 80 bytes a través de una FIFO y retorna la misma cadena pero invertida a través de la misma FIFO*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO_FILE "/tmp/fifo_twoway"
void reverse_string(char *);//Función que invierte una cadena de caracteres

int main() {
   int fd;//Variable que guarda el file descriptor de la FIFO
   char readbuf[80];//Buffer para almacenar lo leido de la FIFO
   char end[10];//Cadena terminal
   int to_end;//Variable de bandera que determina si se ha recibido un mensaje terminal
   int read_bytes;//Variable que almacena el numero de bytes que se leen de la FIFO
   
   /* Create the FIFO if it does not exist */
   mkfifo(FIFO_FILE, S_IFIFO|0640);//SE crea la FIFO con permisos de lectura escritura
   strcpy(end, "end");//Se almacena la cadena terminal
   fd = open(FIFO_FILE, O_RDWR);//Se abre la FIFO en modo lectura escritura
   while(1) {//Loop de lectura
      read_bytes = read(fd, readbuf, sizeof(readbuf));//Se lee el menaje recibido y se determina su tamaño
      readbuf[read_bytes] = '\0';//Se inicializa el buffer de lectura para incluir un caracter terminal
      printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));//Se imprimie la cadena recibida
      to_end = strcmp(readbuf, end);//Se determina si la cadena recibida fue la cadena terminal
      
      if (to_end == 0) {//En caso de que se haya recibido un mensaje terminal
         close(fd);//Se cierra el flujo
         break;//Se rompe el ciclo de lectura
      }
      reverse_string(readbuf);//Se invierte la ultima cadena recibida
      printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));//Se imprime la cadena invertida
      write(fd, readbuf, strlen(readbuf));//Se envía la cadena invertida a la FIFO
      /*
      sleep - Se detiene el proceso por un momento para asegurarse que el proceso cliente pueda leerlo
      */
      sleep(2);
   }
   return 0;//Se termina la ejecución del programa
}

void reverse_string(char *str) {//Función que invierte una cadena de caracteres
   int last, limit, first;//Variables para almacenar diferentes posiciones de la cadena de caracteres
   char temp;//Variable para guardar caracteres de manera temporal
   last = strlen(str) - 1;//Se asigna a last el valor del último caracter de la cadena recibida
   limit = last/2;//Se asigna a limit el valor de la mitad de la cadena
   first = 0;//Se le asigna a first el valor del comienzo de la cadena
   
   while (first < last) {//Se invierte la cadena cambiado el primer caracter por el último iterativamente
      temp = str[first];
      str[first] = str[last];
      str[last] = temp;
      first++;
      last--;
   }
   return;//Se termina la ejecución de la función
}