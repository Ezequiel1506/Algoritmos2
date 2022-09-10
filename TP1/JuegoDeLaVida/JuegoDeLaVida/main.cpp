#include <iostream>
#include "JuegoDeLaVida.h"
#include "Status.h"

using namespace std;

int main() {

	JuegoDeLaVida juegoDeLaVida;
	
	STATUS status;

	inicializarJuegoDeLaVida(&juegoDeLaVida);
	
	if ((status=imprimirInterfazUsuarioInicial(&juegoDeLaVida)) != OK) {
		return status;
	}
	imprimirInterfazUsuario(&juegoDeLaVida);

	return OK;
}