#include <stdio.h>
#include <stdlib.h>
#include "Entradas.h"
#include "Calculos.h"
#include "Menu.h"

void IniciarMenu () {

	int opcion, subOpcion, flagCalculos;
	float  kilometrosIngresados, precioAerolineas, precioLatam,
		   precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas,
		   precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, diferenciaPrecios;

	kilometrosIngresados= 0;
	precioAerolineas= 0;
	precioLatam= 0;
	flagCalculos=0;

	do
		{
			if (kilometrosIngresados <1) {
				printf("1. Presione '1' para ingresar kilometros: \n");
			}
			else {
				printf("1. Presione '1' para ingresar kilometros: (Km=%.2f)\n", kilometrosIngresados);
			}
			if (precioAerolineas < 1 || precioLatam < 1) {
				printf("2. Presione '2' para ingresar el precio de los vuelos: \n");
			}
			else {
				printf("2. Presione '2' para ingresar el precio de los vuelos: (Aerolineas= %.2f, Latam= %.2f)\n", precioAerolineas, precioLatam);
			}
			printf("3. Presione '3' para calcular todos los costos:\n");
			printf("4. Presione '4' para informar los resultados:\n");
			printf("5. Presione '5' para realizar la carga forzada de datos:\n");
			printf("6. Presione '6' para salir del menu:\n");

			printf("Ingrese una opcion: ");
			scanf("%d", &opcion);
			while (opcion < 0 || opcion > 6) {
				printf("\nError! ingrese una opcion correctamente: ");
				scanf("%d", &opcion);
			}

			system("cls");

			switch (opcion) {
			case 1:
				printf("\nUsted a seleccionado la opcion 1, por favor ingrese la cantidad de kilometros: \n");
				kilometrosIngresados= IngresarFlotante();
				break;
			case 2:
				do
				{
				     printf("\n1. Presione '1' para ingresar el precio de Aerolineas: \n");
				     printf("2. Presione '2' para ingresar el precio de Latam: \n");
				     printf("3. Presione '3' para salir del SubMenu: \n");
				     scanf("%d", &subOpcion);

				     switch(subOpcion) {
				          case 1:
				            printf("Aerolineas, ");
				            precioAerolineas= IngresarFlotante();
				            	break;
				          case 2:
				            printf("Latam, ");
				            precioLatam= IngresarFlotante();
				            	break;
				           case 3:
				            printf("Volviendo al menu principal...\n");
				            system("pause");
				            	break;
				        }
				 }while(subOpcion != 3);
				break;
			case 3:
				if (kilometrosIngresados < 1 || precioAerolineas < 1 || precioLatam <1) {
					printf("\n\nError! Por favor ingrese los datos correspondientes de la opcion 1 y 2 o realice una carga forzada\n\n");
				}
				else {
					printf("Calculo realizado...\n");
						//Aerolineas:
						precioDebitoAerolineas= CalcularDescuento(precioAerolineas);//A
						precioCreditoAerolineas= CalcularInteres(precioAerolineas);//B
						precioBitcoinAerolineas= CarcularBitcoin(precioAerolineas);//C
						precioUnitarioAerolineas= CalcularPrecioUnitario(precioAerolineas, kilometrosIngresados);//D
						//Latam:
						precioDebitoLatam= CalcularDescuento(precioLatam);//A
						precioCreditoLatam= CalcularInteres(precioLatam);//B
						precioBitcoinLatam= CarcularBitcoin(precioLatam);//C
						precioUnitarioLatam= CalcularPrecioUnitario(precioLatam, kilometrosIngresados);//D
						//Diferencia de precio:
						diferenciaPrecios= CalcularDiferencia(precioAerolineas, precioLatam);

						flagCalculos=1;
						system("pause");
				}
				break;
			case 4:
				if (flagCalculos == 0) {
					printf("\n\nError! Para ver los datos primero deben ser calculados en la opcion '3'\n\n");
				}
				else {
					printf("\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n"
						   "\tPrecio base Latam: $%.2f\n"
							"\ta) Precio con tarjeta de debito: $%.2f\n"
							"\tb) Precio con tarjeta de credito: $%.2f\n"
							"\tc) Precio pagando con bitcoin: %.6lf BTC\n"
							"\td) Precio unitario: $%.2f\n\n"
							"\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n"
						    "\tPrecio base Aerolineas: $%.2f\n"
							"\ta) Precio con tarjeta de debito: $%.2f\n"
							"\tb) Precio con tarjeta de credito: $%.2f\n"
							"\tc) Precio pagando con bitcoin : %.6lf BTC\n"
							"\td) Precio unitario: $%.2f\n\n"
							"\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n"
							"\tLa diferencia de precio es : $%.2f\n\n"
							"\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n\n", precioLatam, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam,
										   	   	   	   	   	   	 precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, diferenciaPrecios);
					system("pause");
				}
				break;
			case 5:
				printf("Los valores fueron cargados...\n");
				kilometrosIngresados= 7090;
				precioAerolineas= 162965;
				precioLatam= 159339;
					//Aerolineas:
					precioDebitoAerolineas= CalcularDescuento(precioAerolineas);//A
					precioCreditoAerolineas= CalcularInteres(precioAerolineas);//B
					precioBitcoinAerolineas= CarcularBitcoin(precioAerolineas);//C
					precioUnitarioAerolineas= CalcularPrecioUnitario(precioAerolineas, kilometrosIngresados);//D
					//Latam:
					precioDebitoLatam= CalcularDescuento(precioLatam);//A
					precioCreditoLatam= CalcularInteres(precioLatam);//B
					precioBitcoinLatam= CarcularBitcoin(precioLatam);//C
					precioUnitarioLatam= CalcularPrecioUnitario(precioLatam, kilometrosIngresados);//D
					//Diferencia de precio:
					diferenciaPrecios= CalcularDiferencia(precioAerolineas, precioLatam);
					printf("\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n"
							"\tPrecio base Latam: $%.2f\n"
							"\ta) Precio con tarjeta de debito: $%.2f\n"
							"\tb) Precio con tarjeta de credito: $%.2f\n"
							"\tc) Precio pagando con bitcoin: %.6lf BTC\n"
							"\td) Precio unitario: $%.2f\n\n"
							"\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n"
							"\tPrecio base Aerolineas: $%.2f\n"
							"\ta) Precio con tarjeta de debito: $%.2f\n"
							"\tb) Precio con tarjeta de credito: $%.2f\n"
							"\tc) Precio pagando con bitcoin : %.6lf BTC\n"
							"\td) Precio unitario: $%.2f\n\n"
							"\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n"
							"\tLa diferencia de precio es : $%.2f\n\n"
							"\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n\n", precioLatam, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam,
															   	   	   	   	precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, diferenciaPrecios);
				system("pause");
				break;
			case 6:
				printf("\nHasta luego, vuelva pronto!!!");
				break;
			}
			system("cls");
		}while (opcion != 6);
}
