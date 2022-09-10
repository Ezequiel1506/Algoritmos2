#include "Tablero.h"
#include <iostream>
using namespace std;

void inicializarTablero(Tablero * tablero) {
	setearAnchoMaximo(tablero, ANCHO_MAXIMO);
	setearAltoMaximo(tablero, ALTO_MAXIMO);
	llenarTableroCelulasMuertas(tablero);
}

void llenarTableroCelulasMuertas(Tablero * tablero) {
	for (int i = 1; i < obtenerAltoMaximo(tablero) ; i++){
		for (int j = 1; j < obtenerAnchoMaximo(tablero); j++){
			Celula celula;
			setearEstadoDeCelula(&celula,MUERTA);
			setearCelulaEnTablero(tablero, celula, i, j);
		}
	}
}

void setearAnchoMaximo(Tablero * tablero, int anchoMaximo) {
	tablero->anchoMaximo = anchoMaximo;
}

void setearAltoMaximo(Tablero * tablero, int altoMaximo) {
	tablero->altoMaximo = altoMaximo;
}

int obtenerAnchoMaximo(Tablero * tablero) {
	return tablero->anchoMaximo;
}

int obtenerAltoMaximo(Tablero * tablero) {
	return tablero->altoMaximo;
}

Celula * obtenerCelulaEnTablero(Tablero * tablero, int fila, int columna) {

	 return &(tablero->matrizCelulas[fila - 1][columna - 1]);
}

void setearCelulaEnTablero(Tablero * tablero, Celula celula, int fila, int columna) {

	tablero->matrizCelulas[fila - 1][columna - 1] = celula;
}

int contarCantidadVecinosVivos(Tablero * tablero, int x, int y) {

	int vecinosVivos = 0;

	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			//Control no caer en los bordes para considerar informacion que esta en otro lugar de memoria
			if (i < 0 || j < 0 || i == tablero->altoMaximo || j == tablero->anchoMaximo) {
				continue;
			}
			//Salteo mi posicion ya que no me quiero contar a mi misma, solo mis vecinos
			if (i == x && j == y) {
				continue;
			}

			Celula * celulaVecina = obtenerCelulaEnTablero(tablero, i, j);
			vecinosVivos += obtenerEstadoCelula(celulaVecina) == VIVA ? 1 : 0;
			//cout << "la celula de " << i << j << "esta: " << obtenerEstadoCelula(celulaVecina)<<" y tiene: "<<vecinosVivos << endl;
		}
	}
	return vecinosVivos;
}

int contarTotalCelulasVivas(Tablero * tablero) {
	int totalCelulasVivas = 0;

	for (int i = 1; i < tablero->altoMaximo; i++) {
		for (int j = 1; j < tablero->anchoMaximo; j++) {

			Celula * c = obtenerCelulaEnTablero(tablero, i, j);
			if (obtenerEstadoCelula(c) == VIVA) {
				totalCelulasVivas++;
			}
		}
	}
	return totalCelulasVivas;
}

