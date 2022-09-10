#ifndef TABLERO_H
#define TABLERO_H
#include "Celula.h"

static const int ALTO_MAXIMO = 20;
static const int ANCHO_MAXIMO = 80;
static const int TOTAL_CELULAS = 1600;

/*Tablero es definido como un struct.Tiene un alto y ancho y cada celda es una celula
que puede tener 2 estados: Viva o Muerta.*/
typedef struct {
	int anchoMaximo;
	int altoMaximo;
	Celula matrizCelulas[ALTO_MAXIMO][ANCHO_MAXIMO];
} Tablero;

//Funcion para inicializar el tablero
void inicializarTablero(Tablero * tablero);
//Funcion para obtener el ancho maximo del tablero
int obtenerAnchoMaximo(Tablero * tablero);
//Funcion para obtener el alto maximo del tablero
int obtenerAltoMaximo(Tablero * tablero);
//Funcion para setear el ancho maximo del tablero
void setearAnchoMaximo(Tablero * tablero, int anchoMaximo);
//Funcion para setear el alto maximo del tablero
void setearAltoMaximo(Tablero * tablero, int altoMaximo);
//Funcion para obtener una celula del tablero en la posicion [fila][columna]
Celula * obtenerCelulaEnTablero(Tablero * tablero, int fila, int columna);
//Funcion para setear una celula en el tablero en la posicion [fila][columna]
void setearCelulaEnTablero(Tablero * tablero, Celula celula, int fila, int columna);
//Funcion para contar la cantidad de vecinos vivos que tiene una celular en la posicion [fila][columna]
int contarCantidadVecinosVivos(Tablero * tablero, int x, int y);
//Funcion para contar la cantidad total de celulas vivas en el tablero
int contarTotalCelulasVivas(Tablero * tablero);
//Funcion para llenar el tablero con celulas muertas
void llenarTableroCelulasMuertas(Tablero * tablero);

#endif
