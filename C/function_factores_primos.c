#include <stdio.h>

int numero;             //El numero que examinaremos.
int factores[1000];     //Arreglo para almacenar factores de "numero".
int i_factores=0;       //Indice para recorrer el arreglo "factores[]".


int main(){

    int i=2;            

               //Empezaremos a verificar todos los factores desde 2.
               //Pues el numero 1 es factor de todos los numeros.

    printf("\n\t\tIntroduce un numero: ");
    scanf("%d", &numero);
    
        while(i<=numero) {
    
            if((numero%i)==0) {           // a%b=0, implica que b es factor de a.
                 factores[i_factores]=i;  // Añadimos el factor al arreglo.
                 numero=numero/i;         // Procesamos la variable "numero".
                 i_factores++;            // Incrementamos indice de arreglo
                                          // para el siguiente numero.
             continue;
            }
            i++;                          //Incrementamos indice.
        }
    
    /* Rutina para imprimir */
    i=0;
    
    
    printf("\t\tSus facatores son: 1 ");
    
        while(i < i_factores) {
            printf(" %d ", factores[i]);
            i++;
        }
    
    printf("\n");
    printf("\t\tEl indice 4 es: %d", factores[3]);
    printf("\n");
    
    return 0;
}

