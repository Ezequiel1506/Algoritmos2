#include "JuegoDeLaVida.h"


void imprimirJuegoDeLaVida(JuegoDeLaVida * juegoDeLaVida) {

	int altoMaximo = obtenerAltoMaximo(juegoDeLaVida->pTableroActual);
	int anchoMaximo = obtenerAnchoMaximo(juegoDeLaVida->pTableroActual);

	cout << "+++++++" << endl;
	cout << "TABLERO" << endl;
	cout << "+++++++" << endl;

	for (int i = 1; i < altoMaximo; i++) {
		for (int j = 1; j < anchoMaximo; j++) {
			Celula * celula = obtenerCelulaEnTablero(juegoDeLaVida->pTableroActual, i, j);
			//cout << "|";
			cout << obtenerEstadoCelula(celula);
			//cout << "|";
		}
		cout << endl;
	}
	cout << endl;
}

void inicializarJuegoDeLaVida(JuegoDeLaVida * juegoDeLaVida) {

	//Inicalizo los punteros para cada tablero
	juegoDeLaVida->pTableroActual = &(juegoDeLaVida->tableroActual);
	juegoDeLaVida->pTableroSiguiente = &(juegoDeLaVida->tableroSiguiente);
	//Inicializo los tableros
	inicializarTablero(juegoDeLaVida->pTableroActual);
	inicializarTablero(juegoDeLaVida->pTableroSiguiente); 
	juegoDeLaVida->celulasVivasTotal = 0;
	juegoDeLaVida->celulasMuertasUltimoTurno = 0;
	juegoDeLaVida->celulasNacidasUltimoTurno = 0;
	juegoDeLaVida->nacimientosTotal = 0;
	juegoDeLaVida->muertesTotal = 0;
	juegoDeLaVida->numeroTurno = 0;
	juegoDeLaVida->estadoCongelado = false;
}

void ejecutarTurno(JuegoDeLaVida * juegoDeLaVida) {


	int anchoMaximo = obtenerAnchoMaximo(&(juegoDeLaVida->tableroActual));
	int altoMaximo = obtenerAltoMaximo(&(juegoDeLaVida->tableroActual));

	Tablero * pTableroAuxiliar;

	for (int i = 1; i < altoMaximo; i++){
		for (int j = 1; j < anchoMaximo; j++){

			Celula * celulaActual = obtenerCelulaEnTablero(juegoDeLaVida->pTableroActual, i, j);
			int cantidadVecinosVivos = contarCantidadVecinosVivos(juegoDeLaVida->pTableroActual, i, j);

			ESTADO_DE_CELULA estadoCelulaActual = obtenerEstadoCelula(celulaActual);
			//cout <<"Estado Actual: " << estadoCelulaActual << " de la pos:" << i << j << "Y tiene "<< cantidadVecinosVivos;
			ESTADO_DE_CELULA nuevoEstadoCelula = definirProximoEstadoCelula(celulaActual, cantidadVecinosVivos, estadoCelulaActual);
			//cout << "Estado nuevo:  " <<  nuevoEstadoCelula << " de la pos:" << i << j << endl;
			Celula celulaNueva;
			setearEstadoDeCelula(&celulaNueva, nuevoEstadoCelula);
			/*Asigno los nuevos valores de estado de celulas en el tablero del turno siguiente*/
			setearCelulaEnTablero(juegoDeLaVida->pTableroSiguiente, celulaNueva, i, j); //Tener cuidado de pegarle al tablero correcto
			contarCambios(juegoDeLaVida, nuevoEstadoCelula, estadoCelulaActual);
			contarEstados(juegoDeLaVida, estadoCelulaActual);
		}
	}
	/*Utilizo un puntero auxiliar para moverme entre tableros*/
	pTableroAuxiliar = juegoDeLaVida->pTableroActual;
	juegoDeLaVida->pTableroActual = juegoDeLaVida->pTableroSiguiente;
	juegoDeLaVida->pTableroSiguiente = pTableroAuxiliar;
	juegoDeLaVida->numeroTurno++;

}

void contarEstados(JuegoDeLaVida * juegoDeLaVida, ESTADO_DE_CELULA estadoCelula) {
	if (estadoCelula == VIVA) {
		juegoDeLaVida->celulasVivasTotal++;
	}
	if (estadoCelula == MUERTA) {
		juegoDeLaVida->celulasMuertasTotal++;
	}

}

void resetearMetricasUltimoTurno(JuegoDeLaVida * juegoDeLaVida) {
	juegoDeLaVida->celulasMuertasUltimoTurno = 0;
	juegoDeLaVida->celulasNacidasUltimoTurno = 0;
}

ESTADO_DE_CELULA definirProximoEstadoCelula(Celula * celula, int cantidadVecinosVivos, ESTADO_DE_CELULA estadoCelulaActual){
	/*Reglas:
	- Una célula muerta con exactamente 3 células vecinas vivas "nace" (al turno siguiente estará viva)
	- Una célula viva con 2 ó 3 células vecinas vivas sigue viva, en otro caso muere o permanece muerta (por "soledad" o "superpoblación")
	*/
	if (estadoCelulaActual == VIVA && cantidadVecinosVivos != 3 && cantidadVecinosVivos != 2) {
		return MUERTA;
	}
	else if (estadoCelulaActual == MUERTA && cantidadVecinosVivos == 3) {
		return VIVA;
	}
	return estadoCelulaActual;

}

void contarCambios(JuegoDeLaVida * juegoDeLaVida, ESTADO_DE_CELULA nuevoEstadoCelula, ESTADO_DE_CELULA estadoCelulaActual) {
	if (nuevoEstadoCelula != estadoCelulaActual) {
		if (nuevoEstadoCelula == MUERTA) {
			juegoDeLaVida->celulasMuertasUltimoTurno++;
			juegoDeLaVida->muertesTotal++;
		}
		else{
			juegoDeLaVida->celulasNacidasUltimoTurno++;
			juegoDeLaVida->nacimientosTotal++;
		}
	}
}

void imprimirInterfazUsuario(JuegoDeLaVida * juegoDeLaVida) {
	int opcionUsuario;

	cout << "************************************" << endl;
	cout << "Elija la opcion que desee ejecutar: " << endl;
	cout << "1) Ejecutar Turno"<< endl;
	cout << "2) Reiniciar Juego"<< endl;
	cout << "3) Terminar Juego"<< endl;
	cout << "************************************" << endl;
	cin >> opcionUsuario;
	cout << endl;
	switch (opcionUsuario) {
	case 1:

		resetearMetricasUltimoTurno(juegoDeLaVida);
		ejecutarTurno(juegoDeLaVida);
		imprimirJuegoDeLaVida(juegoDeLaVida);
		determinarEstadoJuego(juegoDeLaVida);
		mostrarMetricas(juegoDeLaVida);
		imprimirInterfazUsuario(juegoDeLaVida);
		break;

	case 2:
		inicializarJuegoDeLaVida(juegoDeLaVida);
		cout << "################" << endl;
		cout << "Juego Reiniciado" << endl;
		cout << "################" << endl;
		cout << endl;
		imprimirInterfazUsuarioInicial(juegoDeLaVida);
		break;

	case 3:
		cout << "Juego finalizado" << endl;
		break;

	default:
		cout << "Opcion no valida" << endl;
		imprimirInterfazUsuario(juegoDeLaVida);
		break;

	}
}

STATUS imprimirInterfazUsuarioInicial(JuegoDeLaVida * juegoDeLaVida) {
	int cantidadCelulasIniciales;
	int ubicacionDeCelulaInicialFila;
	int ubicacionDeCelulaInicialColumna;
	cout << "##################################################################" << endl;
	cout << "                Bienvenido al Juego De La Vida                    " << endl;
	cout << "##################################################################" << endl;
	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "Ingrese la cantidad de celulas con las cuales iniciar el juego: ";
	cin >> cantidadCelulasIniciales;
	if (cantidadCelulasIniciales > TOTAL_CELULAS) {
		return CANTIDAD_DE_CELULAS_SUPERIORES_AL_LIMITE;
	}
	for (int i = 0; i < cantidadCelulasIniciales; i++) {
		cout << "---------"<<endl;
		cout << "Celula " << i + 1 << endl;
		cout << "---------" << endl;
		cout << "Ubicacion en Fila: ";
		cin >> ubicacionDeCelulaInicialFila;
		if (ubicacionDeCelulaInicialFila > obtenerAnchoMaximo(juegoDeLaVida->pTableroActual)) {
			return UBICACION_DE_FILA_NO_DISPONIBLE;
		}
		cout << "Ubicacion en columna: ";
		cin >> ubicacionDeCelulaInicialColumna;
		cout << endl;
		if (ubicacionDeCelulaInicialColumna > obtenerAltoMaximo(juegoDeLaVida->pTableroActual)) {
			return UBICACION_DE_COLUMNA_NO_DISPONIBLE;
		}
		setearCelulaInicial(juegoDeLaVida, ubicacionDeCelulaInicialFila, ubicacionDeCelulaInicialColumna);
	}
	imprimirJuegoDeLaVida(juegoDeLaVida);

	return OK;
}

void setearCelulaInicial(JuegoDeLaVida * juegoDeLaVida, int fila, int columna) {
	Celula celulaInicial;
	setearEstadoViva(&celulaInicial);
	setearCelulaEnTablero(juegoDeLaVida->pTableroActual, celulaInicial, fila, columna);
}

void mostrarMetricas(JuegoDeLaVida * juegoDeLaVida){
	float promedioMuertes = juegoDeLaVida->muertesTotal / (juegoDeLaVida->numeroTurno);
	float promedioNacimientos = juegoDeLaVida->nacimientosTotal / (juegoDeLaVida->numeroTurno);

	cout << "###################################" << endl;
	cout << "-----------------------------------" << endl;
	cout << "            METRICAS               " << endl;
	cout << "-----------------------------------" << endl;

	cout << "Celulas vivas actuales: " << contarTotalCelulasVivas(juegoDeLaVida->pTableroActual) << endl;
	cout << "Nacimientos en el ultimo turno: " << juegoDeLaVida->celulasNacidasUltimoTurno << endl;
	cout << "Muertes en el ultimo turno: " << juegoDeLaVida ->celulasMuertasUltimoTurno << endl;
	cout << "Promedio de nacimientos: " << promedioNacimientos << endl;
	cout << "Promedio de muertes: " << promedioMuertes << endl;
	if (juegoDeLaVida->estadoCongelado) {
		cout << "Juego en estado de equilibrio" << endl;
	}
	else {
		cout << "Juego en dinamismo" << endl;
	}
	cout << "###################################" << endl;

	cout << endl;
}

void determinarEstadoJuego(JuegoDeLaVida * juegoDeLaVida) {
	if (juegoDeLaVida->celulasNacidasUltimoTurno == 0 && juegoDeLaVida->celulasMuertasUltimoTurno == 0) {
		juegoDeLaVida->estadoCongelado = true;
	}

}