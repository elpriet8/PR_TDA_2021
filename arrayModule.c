//
//  arrayModule.c
//  
//
//  Created by Diego Prieto on 22/03/21.
//

#include "arrayModule.h"

void toArray(float **array,float *number,int *curfila,int *curcol,int *filas,int *columnas);
void printArray(float **array,int *filas,int *cols);
float* allocateArrayMem(int *filas,int *columnas);

void printArray(float **array,int *filas,int *cols){
    for(int f=0;f<*filas;f++){
        for(int c=0;c<*cols;c++){
            printf(" %f ",array[f][c]);
            if(c == *cols-1){
                printf("\n");
            }
        }
    }
}

void toArray(float **array,float *number,int *curfila,int *curcol,int *filas, int *columnas){
    array[*curfila][*curcol] = *number;
}

float* allocateArrayMem(int *filas,int *columnas){
    float **array = (float**)malloc((*filas)*sizeof(float*));
    for(int i=0;i<(*filas);i++){
        array[i] = (float*)malloc((*columnas)*sizeof(float));
    };
    return array;
}