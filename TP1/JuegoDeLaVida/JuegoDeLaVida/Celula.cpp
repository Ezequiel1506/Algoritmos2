#include "Celula.h"

void iniciarCelula(Celula * celula, ESTADO_DE_CELULA estadoInicial)
{
	setearEstadoDeCelula(celula, estadoInicial);
}

ESTADO_DE_CELULA obtenerEstadoCelula(Celula * celula) {
	return celula->estado;
}

void setearEstadoDeCelula(Celula * celula, ESTADO_DE_CELULA nuevoEstado) {
	celula->estado = nuevoEstado;
}

void setearEstadoMuerta(Celula * celula) {
	celula->estado = MUERTA;
}

void setearEstadoViva(Celula * celula) {
	celula->estado = VIVA;
}