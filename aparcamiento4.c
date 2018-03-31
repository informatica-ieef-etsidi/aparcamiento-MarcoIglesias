#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#define NUMPLAZAS 3
struct plazas {
	int estado;
	char vehiculo;
	char matricula[8];
};

struct usuario {
	char nombre[50];
	char contra[50];
};

void main() {

	system("color A5");
	struct usuario persona1 = { "admin", "1234" };
	struct plazas plaza[NUMPLAZAS] = { 0, 'C' };

	char cliente[50], password[50];
	int i = 0, j, z = 2, h, x, b, w, m, t, a = 0;
	int orden1, orden2, reservar;
	char opcion, matriculaduda[8], matriculaduda1[8], matriculaduda3[8], matriculaduda4[8], tipo;
	int opcion2;

	printf("Inicio de sesion, tienes 3 intentos.\n");
	printf("Cuidado con las mayusculas.\n");
	system("pause");
	system("cls");

	for (j = 0; j < 3; j++) {
		printf("Introduzca su usuario.\n");
		gets(cliente);
		printf("Introduzca su contraseña.\n");
		gets(password);

		if (strcmp(cliente, persona1.nombre) == 0) {
			if (strcmp(password, persona1.contra) == 0) {
				printf("Entrando...\n");
				i = 1;
				j = 8;
				system("pause");
				system("cls");
			}
		}
		else {
			printf("Usuario o contraseña no validos.\n");
			printf("Le quedan %d intentos.\n", z);
			z--;
			system("pause");
			system("cls");
		}

	}


	
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

			for (h = 0; h < NUMPLAZAS; h++) {


				if (plaza[h].estado == 0) {

					printf("Se le ha asignado la plaza %d.\n", h + 1);
					printf("Que tipo de vehiculo usa. Coche, pulse C o moto, pulse M.\n");
					scanf_s("%c", &plaza[h].vehiculo);
					getchar();

					if (plaza[h].vehiculo == 'm' || plaza[h].vehiculo == 'c' || plaza[h].vehiculo == 'M' || plaza[h].vehiculo == 'C') {

						printf("Introduzca su matricula.\n");
						scanf_s("%s", plaza[h].matricula, 8);
						getchar();

						for (b = 0 ; b < NUMPLAZAS ; b++) {
							
							if (h == b) {

							}
							else {

								if (strcmp(plaza[h].matricula, plaza[b].matricula) == 0) {
									printf("Ese vehiculo ya esta estacionado en la plaza %d.\n", b + 1);
									break;
								}
								else {
									plaza[h].estado = 1;
								}
							}
						}


					}
					else {
						printf("Opcion no valida.\n");
						system("pause");
						system("cls");
						break;
					}

					system("pause");
					system("cls");
					break;
				}

			}
			break;

		case 'a':
		case 'A': //opcion abandonar		
			printf("Cual es su matricula.\n");
			scanf_s("%s", matriculaduda, 8);
			getchar();

			for (b = 0; b < NUMPLAZAS ; b++) {
				
				if (strcmp(matriculaduda, plaza[b].matricula) == 0) {
					printf("Has abandonado la plaza %d con tu vehiculo %c.\n", b + 1, plaza[b].vehiculo);
					plaza[b].estado = 0;
					a = 1;
				}

			}

			if (a == 0) {
				printf("Ese vehiculo no se encuentra en el parking.\n");
			}
			else {
				a = 0;
			}
			
			system("pause");
			system("cls");
			break;

		case 'e':
		case 'E': //opcion de ver el estado

			for (b = 0; b < NUMPLAZAS ; b++) {

				if (plaza[b].estado == 1) {
					printf("Plaza %d ocupada - vehiculo: %c - matricula: %s.\n", b + 1, plaza[b].vehiculo, plaza[b].matricula);

				}
				else {
					printf("Plaza %d libre.\n", b + 1);

				}

			}

			system("pause");
			system("cls");
			break;

		case'b':
		case'B'://opcion buscar matricula
			printf("Cual es su matricula.\n");
			scanf_s("%s", matriculaduda4, 8);
			getchar();

			for (b = 0; b < NUMPLAZAS ; b++) {

				if (strcmp(matriculaduda4, plaza[b].matricula) == 0) {
					printf("Ese vehiculo se encuentra la plaza %d.\n", b + 1);
					a = 1;
				}
		
			}

			if (a == 0) {
				printf("Ese vehiculo no se encuentra en el parking.\n");
			}
			else {
				a = 0;
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
			break;
		}

	}
	system("PAUSE");

}