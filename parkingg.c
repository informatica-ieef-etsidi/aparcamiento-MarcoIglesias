#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
void main() {

	system("color A5");

	int i = 1, a = 0, b = 0; // a es una plaza y b otra
	int orden1, orden2, reservar;
	char opcion, matricula1[8] , matricula2[8] , opcion2,matriculaduda[8];
	while (i == 1) {
		//Partimos de las dos plazas libres, si hay dos libres se asigna primero la a por comodidad

		printf("Selecione una de estas opciones:\n");
		printf("R - Reservar plaza.\n");
		printf("A - Abandonar plaza.\n");
		printf("E - Estado del aparcamiento.\n");
		printf("B - Buscar vehiculo por matricula.\n");
		printf("S - Salir del programa.\n");

		scanf_s("%c", &opcion);
		getchar();
		system("cls");

		switch (opcion) { //menu de opciones, reservar o abandonar una plaza o ver el  estado de las mismas

		case'r':
		case 'R': // opcion de reservar
		
			
			if (a == 0 && b == 1) {
				printf("La plaza A esta libre, introduzca su matricula.\n");
				a = 1;
				printf("Introduzca su matricula.\n");
				scanf_s("%s", matricula1, 8);
				getchar();
				system("PAUSE");
				system("cls");
			}
			else if (a == 0 && b == 0) {
				printf("Ambas plazas estan libres, se le ha asignado la A.\n");
				a = 1;
				printf("Introduzca su matricula.\n");
				scanf_s("%s", matricula1, 8);
				getchar();
				system("PAUSE");
				system("cls");
			}
			else if (a == 1 && b == 0) {
				printf("Se le ha asignado la plaza B.\n");
				b = 1;
				printf("Introduzca su matricula.\n");
				scanf_s("%s", matricula2, 8);
				reservar = strcmp(matricula1, matricula2);
				if (reservar == 0) {
					b = 0;
					printf("Esa matricula ya esta en uso.\n");
				}
				getchar();
				system("PAUSE");
				system("cls");
			}
			else {
				printf("Las dos plazas estan ocupadas.\n");
				system("PAUSE");
				system("cls");
			}	
		break;
		//la matricula2 es la plaza B por logica porque la A es la primera que se llena y ademas es una forma de asignar plaza a unn coche

		case'a':
		case 'A': //opcion abandonar
			if (a==1 || b==1){
				printf("¿En que plaza estaba, A o B?\n");
				scanf_s("%c", &opcion2);
				getchar();

				switch (opcion2) {
				case 'a':
				case 'A':
					if (a == 1) {
						printf("La plaza A queda libre.\n");
						a = 0;

					}
					else {
						printf("Usted no estaba en esa plaza.\n");
					}
					system("PAUSE");
					system("cls");
					break;
				case 'b':
				case 'B':
					if (b == 1) {
						printf("La plaza B queda libre\n");
						b = 0;
					}
					else {
						printf("Usted no estaba en esa plaza.\n");
					}
					system("PAUSE");
					system("cls");
					break;
				default:
					printf("Esa plaza no existe.\n");
					system("PAUSE");
					system("cls");
					break;

				}

			} 
			else {
				printf("No hay plazas ocupadas.\n");
				system("pause");
				system("cls");
			}

		break;
		case 'e':
		case 'E': //opcion de ver el estado
			
			if (a == 0 && b == 0) {
				printf("Plaza A - Libre \n");
				printf("Plaza B - Libre \n");
				system("PAUSE");
				system("cls");
			}
			else if (a == 0 && b == 1) {
				printf("Plaza A - Libre \n");
				printf("Plaza B - Ocupada - Matricula %s \n", matricula2);
				system("PAUSE");
				system("cls");
			}
			else if (a == 1 && b == 0) {
				printf("Plaza A - Ocupada - Matricula %s \n", matricula1);
				printf("Plaza B - Libre\n");
				system("PAUSE");
				system("cls");
			}
			else {
				printf("Plaza A - Ocupada - Matricula %s \n", matricula1);
				printf("Plaza B - Ocupada - Matricula %s \n", matricula2);
				system("PAUSE");
				system("cls");
			}
			break;

		case'b':
		case'B'://opcion buscar matricula
			printf("Cual es su matricula.\n");
			scanf_s("%s", matriculaduda, 8);
			getchar();
			orden1=strcmp(matriculaduda, matricula1);
			orden2 = strcmp(matriculaduda, matricula2);
			if (orden1 == 0) {
				printf("Ese coche esta en la plaza 1.\n");
			}
			else if (orden2 == 0) {
				printf("Ese coche esta en la plaza 2.\n");
			}
			else {
				printf("Ese coche no esta en el parking.\n");
			}
			system("pause");
			system("cls");
			break;

		case 's':
		case 'S':
			i = 0;
			break;
		default:  // si no pone ninunga opcio valida
			printf("Te has equivocado de opcion\n");
			system("pause");
			system("cls");
		}
		

		
	}
	system("PAUSE");
}
