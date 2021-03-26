//
//  prac2.c
//  
//
//  Created by Diego Prieto on 18/03/21.
//

#include "exam1.h"

void fileController(char *filename);
void writeInFile(float *media,float *desv,float *max, float *min,int totalint);
extern void getMatrixSize(int *filas,int *columnas,FILE *fp);
extern float stringtofloat(char *line,int *position);
extern void toFloat(float **array,int *filas, int *columnas,FILE *fp);
extern void printArray(float **array,int *filas,int *cols);
extern float* allocateArrayMem(int *filas,int *columnas);
extern float getMedia(float **array, int *filas, int *columnas);
extern float getDesvEst(float **array, int *filas, int *columnas,float *media);
extern float rangoMax(float **array,int *filas, int *columnas);
extern float rangoMin(float **array,int *filas, int *columnas);


int main(int argc, char *argv[]){
    char filename[21];
    
    printf("Nombre de archivo: ");
    scanf(" %[^\n]",filename);
    
    fileController(filename);
    
    return 0;
}

void fileController(char *filename){
    FILE *fp;
    int columnas=1,filas=0;
    float media,desvest,max,min;
    float **array = NULL;

    fp = fopen(filename,"r");
    if(fp == NULL){
        printf("Error de archivo");
        exit(1);
    }
    // read file dimensions, to float, fill and print array
    getMatrixSize(&filas,&columnas,fp);
    array = allocateArrayMem(&filas,&columnas);

    rewind(fp);
    toFloat(array,&filas,&columnas,fp);

    media = getMedia(array,&filas,&columnas);
    desvest = getDesvEst(array,&filas,&columnas,&media);
    max = rangoMax(array,&filas,&columnas);
    min = rangoMin(array,&filas,&columnas);

    writeInFile(&media,&desvest,&max,&min,columnas*filas);

    printf("\nEstadisticas guardadas en Data_Statistic.txt\n\nGracais, Adios :) \n");
    
    fclose(fp);
    free(array);
}


void writeInFile(float *media,float *desv,float *max, float *min,int totaln){

    FILE *fp1 = fopen("Data_Statistic.txt","w");

    fprintf(fp1,"Total de Datos: %i", totaln);
    fprintf(fp1,"\nMedia: %f",*media);
    fprintf(fp1,"\nDesviacion Estandar: %f",*desv);
    fprintf(fp1,"\nRango \nMax: %f",*max);
    fprintf(fp1,"\nMin: %f",*min);

    fclose(fp1);

}






