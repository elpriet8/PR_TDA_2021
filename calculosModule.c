#include "calculosModule.h"


float getMedia(float **array, int *filas, int *columnas);
float getDesvEst(float **array, int *filas, int *columnas,float *media);
float rangoMax(float **array,int *filas, int *columnas);

float getMedia(float **array, int *filas, int *columnas){
	int n = (*filas)*(*columnas);
	float suma = 0;
    for(int f=0;f<*filas;f++){
        for(int c=0;c<*columnas;c++){
        	suma += array[f][c];
        }
    }
	return suma/n;
}

float getDesvEst(float **array, int *filas, int *columnas,float *media){
	float xsum = 0;
	int n = (*filas) * (*columnas);
	for(int f=0;f<*filas;f++){
        for(int c=0;c<*columnas;c++){
        	if(array[f][c] != 'x' || array[f][c] != 'y')
        	xsum += array[f][c] - *media;
        }
    }
    xsum = sqrt(xsum);
	return xsum/(n-1);
}


float rangoMax(float **array,int *filas, int *columnas){
	float max = 0;
	for(int f=0;f<*filas;f++){
        for(int c=0;c<*columnas;c++){
     		if(array[f][c] > max){
     			max = array[f][c];
     		}   	
    	}
    }
	return max;
}

float rangoMin(float **array,int *filas, int *columnas){
	float min = array[*filas-1][*columnas-1];

	for(int f=0;f<*filas;f++){
        for(int c=0;c<*columnas;c++){
     		if(array[f][c] < min){
     			min = array[f][c];
     		}   	
    	}
    }
	return min;
}

