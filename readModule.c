//
//  readModule.c
//  
//
//  Created by Diego Prieto on 22/03/21.
//

#include "readModule.h"

void getMatrixSize(int *filas,int *columnas,FILE *fp);
float stringtofloat(char *line,int *position);
void toFloat(float **array,int *filas, int *columnas,FILE *fp);
extern void toArray(float **array,float *number,int *curfila,int *curcol,int *filas,int *columnas);



void getMatrixSize(int *filas,int *columnas,FILE *fp){
    char line[1024];
    char start = '0';
    
    while((fgets(line,sizeof(line),fp))){
        // Count Columns just once
        if(start == '0'){
            for(int i = 0;i<strlen(line);i++){
                if(line[i] == ','){
                    *columnas = *columnas + 1;
                }
            }
            start = '1';
        }
        // Add to row count
        *filas = *filas+1;
    }
}

void toFloat(float **array,int *filas, int *columnas,FILE *fp){
    float num;
    char line[1024];
    int curfila = 0;
    
    
    while((fgets(line,sizeof(line),fp))){
        int position = 0;
        for(int i=0;i<*columnas;i++){
            num = stringtofloat(line,&position);
            position++;
            toArray(array,&num,&curfila,&i,filas,columnas);
        }
        curfila++;
    }
}

float stringtofloat(char *line,int *position){
    char number[21];
    float num;
    int n= 0;
    
    for(int p=*position; p<strlen(line); p++){
       if(line[p] > 29 && line [p] <58){
        if(line[p] != ','){
            number[n]= line[p];
            n++;
        }else{
            *position = p;
            return strtof(number,NULL);
        }
    }
    }
    return strtof(number,NULL);
}
