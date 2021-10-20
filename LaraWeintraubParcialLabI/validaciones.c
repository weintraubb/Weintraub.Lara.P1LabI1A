#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#define TAM 500

int getValidInt(char mensaje[], char error[]){
	char numeroSolicitado[TAM];
	int largo;
	int fallo;
	int resultado;

	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroSolicitado);

		largo = strlen(numeroSolicitado);

		for (int i=0;i<largo;i++){


			if (isdigit(numeroSolicitado[i]) || numeroSolicitado[0] == '-'){
				fallo=0;
			}
			else{
				fallo=1;
				printf("%s", error);
				break;
			}
		}

	} while (fallo==1);

	resultado = atoi(numeroSolicitado);

	return resultado;
}

float getValidFloat(char mensaje[], char error[]){
	char numeroSolicitado[TAM];
	int largo;
	int fallo;
	int flag;
	float resultado;

	do{
		flag=1;
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroSolicitado);

		largo = strlen(numeroSolicitado);

		for (int i=0;i<largo;i++){

			if (isdigit(numeroSolicitado[i]) || (numeroSolicitado[i] == '.' && flag==1) || numeroSolicitado[0] == '-'){
				if(numeroSolicitado[i] == '.'){
					flag=0;
				}
				fallo=0;
			}
			else{
				fallo=1;
				printf("%s",error);
				break;

			}
		}

	} while (fallo==1);

	resultado = atof(numeroSolicitado);

	return resultado;
}


int getInt(char mensaje[],int min,int max){
	int numero;


	numero = getValidInt(mensaje,"Dato invalido\n");

	while(numero <min || numero > max){
		printf("Numero invalido, ingrese un numero en el rango pedido (%d-%d)\n",min,max);

		numero = getValidInt(mensaje,"Dato invalido\n");
	}

	return numero;

}

float getFloat(char mensaje[],int min,int max){
	float numero;

	numero = getValidFloat(mensaje,"Dato incorrecto\n");
	while(numero <min || numero > max){
		printf("Numero invalido, ingrese un numero en el rango pedido (%d-%d)\n",min,max);
		numero = getValidFloat(mensaje,"Dato incorrecto\n");
	}

	return numero;

}


void getString (char mensaje [], char error[], char cadena[],int tam)
{
	int flagE=0;
	int largo;

	do{

		if(flagE)
		{
            printf("%s", error);
		}
		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);
		largo = strlen(cadena);
		if(cadena == NULL || largo <2){
			flagE=1;
		}
		else {
			for(int i=0; i<largo; i++){
				if((isdigit(cadena[i]) == 1 && cadena[i]!=' ') || (cadena[i-1]==' ' && cadena[i]==' ')  || (largo<5 && cadena[i]==' ')){
					flagE=1;
					break;
				}
				else{
					flagE=0;
				}

			}
		}
	}while(flagE);
    corregirString(cadena);
}
void corregirString(char cadena[]){
	int largo;

	largo = strlen(cadena);

	strlwr(cadena);

	for(int i=0; i<largo;i++)
    {

		if(i==0 || cadena[i-1]==' '){
			cadena[i] = toupper(cadena[i]);
		}
    }
}

