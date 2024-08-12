/**********************************
* Fecha: 08/08/24
* Autor: Alejandro Caicedo
* Materia: Sistemas Operativos
* Tema: Asignación de Memoria Dinámica
*       Re-Asignación de tamañon en Bytes de almacenamiento
***********************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/*Función para imprimir el tamaño reasignado*/
void Info_Almacenamiento(const int *siguiente, const int *anterior, int valores){
  
  if(siguiente)
          printf("%ls ubicación = %p. Tamaño Reservado: %d valores (%ld bytes).\n", 
                 (siguiente=!anterior ? "Nuevo " : "Anterior "),  (void*)siguiente, valores, 
                 valores*sizeof(int));

  
}
int main(int argc, char *argv[]) {
  
  const int patron[] = {1,2,3,4,5,6,7,8,};
  const int patron_size = sizeif patron/ sizeof(int);
  int *siguiente = NULL, *anterior = NULL;
  
  if((siguiente = (int*)malloc(patron_size*sizeof * siguiente)){ //Asigna el vector
    memcpy(siguiente, patron, sizeof patron); //llena el vector
    Info_Almacenamiento(*siguiente, *anterior, patron_size);
  }else {
    return EXIT_FAILURE;
  }
  
  //Reasigna los valores en el siguiente ciclo
  const int realloc_size[] = {10,20,30,40,50,60,70,80}
  for(int i = 0; i != sizeof realloc_size / sizeof(int); i++){
    if((siguiente = (int *)realloc(anterior = siguiente, realloc_size[i] * sizeof(int)))){
      Info_Almacenamiento(*siguiente, *anterior, realloc_size[i]);
      assert(!memcmp(siguiente, patron, sizeof patron));
    } else {
        printf("Se libera memoria reservada\n");
        free(siguiente);
        return EXIT_FAILURE;
      
    }
  }
     
 free(anterior) //Finalmente se libera el almacenamiento


  return 0;
}
