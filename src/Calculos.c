#include <stdio.h>
#include <stdlib.h>
#include "Entradas.h"
#include "Calculos.h"
#include "Menu.h"

float CalcularDescuento (float nro) { //a
	float retorno;
	int porcentajeDescuento= 10;

	retorno= nro - (nro*porcentajeDescuento/100);

	return retorno;
}

float CalcularInteres (float nro) {//b
	float retorno;
	int porcentajeInteres= 25;

	retorno= nro + (nro*porcentajeInteres/100);

	return retorno;
}

double CarcularBitcoin (float nro) { //c
	double retorno, valorBitcoin;
	valorBitcoin= 4606954.55;

	retorno= nro/valorBitcoin;

	return retorno;
}

float CalcularPrecioUnitario (float nro, int kilometrosIngresados) {//d
	float retorno;

	retorno= nro/kilometrosIngresados;

	return retorno;
}

float CalcularDiferencia (float nro1, float nro2) {//e
	float retorno;

	if (nro1 > nro2) {
		retorno= nro1-nro2;
	}
	else {
		retorno= nro2-nro1;
	}

	return retorno;
}
