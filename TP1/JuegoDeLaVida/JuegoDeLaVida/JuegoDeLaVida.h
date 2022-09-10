#ifndef JUEGODELAVIDA_H
#define JUEGODELAVIDA_H

#include <iostream>
#include "Tablero.h"
#include "Status.h"
using namespace std;


typedef struct {
	int celulasVivasTotal;
	int celulasMuertasTotal;
	int nacimientosTotal;
	int muertesTotal;
	int celulasNacidasUltimoTurno;
	int celulasMuertasUltimoTurno;
	int numeroTurno;
	bool estadoCongelado;
	Tablero  tableroActual;
	Tablero tableroSiguiente;
	Tablero * pTableroActual;
	Tablero * pTableroSiguiente;
} JuegoDeLaVida;
//Funcion para imprimir por consola el tablero, las celulas vivas se marcan con 1's y las muertas con 0's
void imprimirJuegoDeLaVida(JuegoDeLaVida * juegoDeLaVida);
//Funcion para iniciar el Juego de la Vida
void inicializarJuegoDeLaVida(JuegoDeLaVida * juegoDeLaVida);
//Funcion para interactuar con el usuario. Si ingresa mas celulas de las que se permiten en el tablero o ubicacion de celula erronea, retorna un mensaje de error.
void imprimirInterfazUsuario(JuegoDeLaVida * juegoDeLaVida);
//Funcion para interactuar al comienzo del juego con el usuario, se le requiere que ingrese la cantidad de celulas vivas con las que desea comenzar el juego y su ubicacion.
STATUS imprimirInterfazUsuarioInicial(JuegoDeLaVida * juegoDeLaVida);
//Funcion para definir el proximo estado de una celula, se le debe indicar que celula analizar, la cantida de vecinos vivos y su estado actual
ESTADO_DE_CELULA definirProximoEstadoCelula(Celula * celula, int cantidadVecinosVivos, ESTADO_DE_CELULA estadoCelulaActual);
//Funcion para contar cuantos cambios de estado ocurrieron en el juego
void contarCambios(JuegoDeLaVida * juegoDeLaVida, ESTADO_DE_CELULA nuevoEstadoCelula, ESTADO_DE_CELULA estadoCelulaActual);
//Funcion para setear el estado inicial de una celula en el tablero
void setearCelulaInicial(JuegoDeLaVida * juegoDeLaVida, int fila, int columna);
//Funcion para ejecutar el turno
void ejecutarTurno(JuegoDeLaVida* juegoDeLaVida);
//Funcion para reestablecer a cero los contadores de celulas nacidas y muertas durante el ultimo turno
void resetearMetricasUltimoTurno(JuegoDeLaVida* juegoDeLaVida);
/*Funcion para mostrar las metricas del juego :
- Celulas vivas actuales
- Nacimientos en el ultimo turno
- Muertes en el ultimo turno
- Promedio de nacimientos
- Promedio de muertes
- Estado del juego*/
void mostrarMetricas(JuegoDeLaVida * juegoDeLaVida);
//Funcion para determinar la cantidad de celulas en estado VIVO y Muerto
void contarEstados(JuegoDeLaVida* juegoDeLaVida, ESTADO_DE_CELULA estadoCelula);
//Funcion para determinar si el juego se encuentra en estado Dinamico (siguen sucediendo nacimientos y muertes) o estatico
void determinarEstadoJuego(JuegoDeLaVida* juegoDeLaVida);

#endif 
