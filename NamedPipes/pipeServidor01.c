/**********************************
* Fecha: 03/010/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Named pipes
* Tópico: Servidor de la named pipe
***********************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO_FILE "MYFIFO"//Se define el nombre del fichero de la FIFO
int main() {
   int fd;//Se crea variable para almacenar el dentificador del proceso
   char readbuf[80];//Se crea un buffer de 80 caracteres
   char end[10];//Se crea la variable par guardadar la cadena terminal
   int to_end;//Se define una variable para guardar la comparación
   int read_bytes;//Se define una validable para guardar el tamaño de los mesajes
   
   printf("\n \t\t >>>>>>> INICIO SERVIDOR <<<<<<<<< \n");//Se despliega un mensaje al abrir el servidor
   /* Create the FIFO if it does not exist */
   mknod(FIFO_FILE, S_IFIFO|0640, 0);//Se crea el FIFO con permisos de lectura escritura
   strcpy(end, "end");//Se le asigna el valor end a la cadena
   while(1) {//Se inicia un bucle infinito de escucha
       fd = open(FIFO_FILE, O_RDONLY); //Se abre el fifo en modo lectura
       read_bytes = read(fd, readbuf, sizeof(readbuf));//Se lee la cadena recibida del fifo y se guarda la cantidad de bytes del mensaje
       readbuf[read_bytes] = '\0';//Se lee el buffer y se agrega un final de linea
       printf("Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));//Se imprime el mensaje recibido
       to_end = strcmp(readbuf, end);//Se verifica si el mensaje recibido es el mensaje terminal
       if (to_end == 0) {//Si es el mensaje terminal se cierra la pipe y se termina el proceso
          close(fd);
          break;
       }
    }
}