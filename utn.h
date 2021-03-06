#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getString(char* array,char* mensaje,char* mensajeError,int min,int max,int intentos);
int utn_getInt(int* numero, char* mensaje,char* mensajeError,int rangoMin, int rangoMax);
int utn_getChar(char* letra,char* mensaje,char* mensajeError,char letra1, char letra2);
float utn_getFloat(float* numero, char* mensaje,char* mensajeError,float rangoMin, float rangoMax);
int utn_getLong(long* numero, char* mensaje,char* mensajeError,int rangoMin, int rangoMax);
int utn_getFactorial(double* pFactorial, int numero);
float sacarPromedio(int numero1, int numero2);


#endif // UTN_H_INCLUDED
