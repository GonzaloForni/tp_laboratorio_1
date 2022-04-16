/*============================== Trabajo Practico Nº1 Gonzalo Forni Div 1F ==============================*/
#include <stdio.h>
#include <stdlib.h>
#include "Entradas.h"
#include "Calculos.h"
#include "Menu.h"

void IniciarMenu ();
float IngresarFlotante();
float CalcularDescuento (float nro);//a
float CalcularInteres (float nro);//b
double CarcularBitcoin (float nro);//c
float CalcularPrecioUnitario (float nro, int kilometrosIngresados);//d
float CalcularDiferencia (float nro1, float nro2);//e

int main(void) {
	setbuf(stdout, NULL);

	IniciarMenu();

	return EXIT_SUCCESS;
}
