/**********************************
* Fecha: 17/10/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Named pipes Bidireccionales
* Tópico: Cliente de la named pipe
***********************************/

/*Este fichero contiene un programa cliente que envía un mensaje ingresado por el usuario a un servidor a través de una FIFO y recibe un mensaje enviado de vuelta por el servidor*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO_FILE "/tmp/fifo_twoway"
int main() {
   int fd;//Variable que almacena el file descriptor de la FIFO
   int end_process;//Variable de bandera que determina si se debe terminar el proceso
   int stringlen;//Variable que almacena el tamaño de una cadena de caracteres
   int read_bytes;//Variable que almacena el tamaño de un mensaje recibido
   char readbuf[80];//Variable que almacena el mensaje leido de la FIFO
   char end_str[5];//Variable que almacena la cadena terminal
   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");//Se imprimen instrucciones para el usuario
   fd = open(FIFO_FILE, O_CREAT|O_RDWR);//Se abre la FIFO en modo lectura escritura
   strcpy(end_str, "end");//Se copia la cadena terminal
   
   while (1) {//Ciclo de lectura escritura
      printf("Enter string: ");//Se imprime instrucción para la entrada de datos
      fgets(readbuf, sizeof(readbuf), stdin);//Se lee la entrada del usuario
      stringlen = strlen(readbuf);//Se obtiene el tamaño de la cadena recibida
      readbuf[stringlen - 1] = '\0';//Se le agrega un caracter terminal a la cadena
      end_process = strcmp(readbuf, end_str);//Se determina si se iingreso la cadena teminal
      
      //printf("end_process is %d\n", end_process);
      if (end_process != 0) {//Si no se ha ingresado la cadena terminal
         write(fd, readbuf, strlen(readbuf));//Se envía la cadena al servidor a través de la FIFO
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));//Se imprime un la cadena envida al usuario
         read_bytes = read(fd, readbuf, sizeof(readbuf));//Se lee el flujo de la FIFO y se almacena del tamaño del mensaje
         readbuf[read_bytes] = '\0';//Se agrega un caracer terminal a la cadena
         printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));//Se imprime el mensaje recibido (El mensaje enviado invertido)
      } else {
         write(fd, readbuf, strlen(readbuf));//Se envía la cadena terminal al servidor
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));//Se imprime la cadena envidad
         close(fd);//Se cierra el flujo de datos de la FIFO
         break;//Se rompe el ciclo de lectura escritura
      }
   }
   return 0;//Se termina la ejecución del proceso
}