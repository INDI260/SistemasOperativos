/**********************************
* Fecha: 03/010/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Named pipes
* Tópico: Cliente de la named pipe
***********************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO_FILE "MYFIFO"

int main() {
   int fd;//Se crea variable para almacenar el dentificador del proceso
   int end_process;//Se crea una variable para almacenar el valor de la comparación con la cadena terminal
   int stringlen;//Se crea una variable para determinar el largo de una cadena de caracteres
   char readbuf[80];//Se crea un buffer de 80 caracteres
   char end_str[5];//Se crea una variable para almacenar la cadena terminal
  
   printf("\n \t\t >>>>>>> INICIO CLIENTE <<<<<<<<< \n");//Se desplega un mensaje de inicio del cliente
   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");//Se imprime un mensaje con indicaciones para el usuario
   fd = open(FIFO_FILE, O_CREAT|O_WRONLY);//Se abre la fifo y se guarda su identificador
   strcpy(end_str, "end");//Se le asigna el valor end a la cadena terminal

   while (1) {
      printf("Enter string: ");
      fgets(readbuf, sizeof(readbuf), stdin);//Se recibe la cadena a enviar
      stringlen = strlen(readbuf);//Se determina el tamaño de la cadena envida
      readbuf[stringlen - 1] = '\0';//Se le agrega un caracter terminal a la cadena
      end_process = strcmp(readbuf, end_str);//Se realiza la comparación de la cadena envida con la cadena terminal

      //printf("end_process is %d\n", end_process);
      if (end_process != 0) {//Si son diferentes se imprime la cadena enviada con su nombre y se envía al servidor
         write(fd, readbuf, strlen(readbuf));
         printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)    strlen(readbuf));
      } else {//Si son iguales se hace lo mismo pero además se cierra la FIFO y se termina la ejecución del proceso
         write(fd, readbuf, strlen(readbuf));
         printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)    strlen(readbuf));
         close(fd);
         break;
      }
   }
   return 0;
}