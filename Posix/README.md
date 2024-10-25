# Principios de hilos con Posix y pthread

Este fichero contiene un ejemplo que introduce conceptos de uso de hilos paralelos, exclusividad mutua, variables condicionales y fundamentos del uso de la bilioteca pthread.
Este programa imprime una cuenta del 1 al 10 por consola usando los elementos anteriormente mencionados.
El comando de compilación debe ser este: gcc -g -pthread prod_cons_posix.c -o prod_cons_posix