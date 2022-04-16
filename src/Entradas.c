#include <stdio.h>
#include <stdlib.h>
#include "Entradas.h"
#include "Calculos.h"

float IngresarFlotante() {

	float retorno;

	printf("Ingrese el numero: ");
	scanf("%f", &retorno);
	while (retorno <= 0) {
		printf("Error! Ingrese correctamente el numero: ");
		scanf("%f", &retorno);
	}

	return retorno;
}
