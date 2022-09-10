#ifndef CELULA_H
#define CELULA_H

//Defino los estados posibles de una celula
enum ESTADO_DE_CELULA {
	MUERTA = 0,
	VIVA = 1
};

//Defino a la celula como un struct, que tiene un estado que es del tipo EstadoDeCelula
typedef struct {
	ESTADO_DE_CELULA estado;
} Celula;

//Funcion para inicializar una celula
void iniciarCelula(Celula * celula, ESTADO_DE_CELULA estadoInicial);
//Funcion para obtener el estado de una celula
ESTADO_DE_CELULA obtenerEstadoCelula(Celula * celula);
//Funcion para setear el estado de una celula
void setearEstadoDeCelula(Celula * celula, ESTADO_DE_CELULA nuevoEstado);
//Funcion para setear estado muerta a una celula
void setearEstadoMuerta(Celula * celula);
//Funcion para setear estado viva a una celula
void setearEstadoViva(Celula * celula);

#endif 