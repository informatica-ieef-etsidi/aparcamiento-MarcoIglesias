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


char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);
int existeUsuario(struct usuario persona1, char username[], char password[]);

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
		m = existeUsuario(persona1, cliente, password);
		if (m == 1) {
			printf("Entrando...\n");
			i = 1;
			j = 8;
			system("pause");
			system("cls");
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

		opcion = menu();
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
						if (esMatriculaValida(plaza[h].matricula) == 0) {
							printf("Matricula no valida.\n");
							system("pause");
							system("cls");
							break;
						}

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
			if (esMatriculaValida(matriculaduda) == 0) {
				printf("Matricula no valida.\n");
				system("pause");
				system("cls");
				break;
			}
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
			if (esMatriculaValida(matriculaduda4) == 0) {
				printf("Matricula no valida.\n");
				system("pause");
				system("cls");
				break;
			}
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

char menu() {
	char opcion;
	printf("Selecione una de estas opciones:\n");
	printf("R - Reservar plaza.\n");
	printf("A - Abandonar plaza.\n");
	printf("E - Estado del aparcamiento.\n");
	printf("B - Buscar vehiculo por matricula.\n");
	printf("S - Salir del programa.\n");

	scanf_s("%c", &opcion);
	return opcion;
}
int esDigitoValido(char caracter) {
	if (caracter < 10 && caracter >= 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int esLetraValida(char caracter) {
	if (("caracter" > 65 && "caracter" < 91) || ("caracter" > 96 && "caracter" < 173)) {
		return 1;
	}
	else
		return 0;
}
int esMatriculaValida(char matricula[]) {
	int longitud,i,contador=0, booleano, contador2=0, booleano2,caracter1, caracter2;
	longitud = strlen(matricula);
	for (i = 0; i < 4;i++) {
			caracter1= matricula[i];
		booleano = esDigitoValido(caracter1);
		if (booleano == 1) {
			contador++;
		}
	}
	for (i = 4; i < longitud;i++) {
		caracter2 = matricula[i];
		booleano2 = esDigitoValido(caracter2);
		if (booleano2 == 1) {
			contador2++;
		}
	}
	if (contador == 4 && contador2 == 3) {
		return 1;
	}
	else {
		return 0;
	}
}
int existeUsuario(struct usuario persona1, char username[], char password[]) {

	int i, j,z;


	if (strcmp(username, persona1.nombre) == 0) {
		if (strcmp(password, persona1.contra) == 0) {
			return 1;
			
		}
	}
	else {
		return 0;
	}
}