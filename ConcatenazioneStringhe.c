/*
 * ConcatenazioneStringhe.c
 * 
 * Copyright 2018 alexmik <alexmik@alexmik_archlinux>
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LENGHT 20
#define N_PAROLE 7

char* concatena(char *nomeFIleA, char *nomeFileB) {
	FILE *listaA;
	listaA = fopen("listaA.txt", "r");
	FILE *listaB;
	listaB = fopen("listaB.txt", "r");
	FILE *listaOUT;
	listaOUT = fopen("listaOUT.txt", "w");
	
	char *stringaA = malloc(sizeof(char) * MAX_STR_LENGHT);
	fscanf(listaA, "%s", stringaA);
	printf("letta stringa dal file A: %s", stringaA);

	char *stringaB = malloc(sizeof(char) * MAX_STR_LENGHT);
	fscanf(listaB, "%s", stringaB);
	printf("letta stringa dal file B: %s", stringaB);
	
	char *strg = malloc(sizeof(char) * ((strlen(stringaA))+(strlen(stringaB) )) );		//alloca porzione di memoria per contenere la stringa di massima lunghezza la somma delle due in input
	strg = strcat(stringaA, stringaB);
	fprintf(listaOUT, "%s", strg);

	fclose(listaA);
	fclose(listaB);
	fclose(listaOUT);

	return strg;
}

int main() {
	char stringaFinale[MAX_STR_LENGHT] = "";
	char stringaA[MAX_STR_LENGHT];
	char stringaB[MAX_STR_LENGHT];
	FILE *fileA= fopen("listaA.txt", "r");
	FILE *fileB= fopen("listaB.txt", "r");
	FILE *fileOut=fopen("listaOut.txt", "a+");
	/*
	for(int i=0; i<N_PAROLE; i++){
		fscanf(fileA, "%s\n", stringaA);
		fscanf(fileB, "%s\n", stringaB);
		strcat(stringaFinale, stringaA);
		strcat(stringaFinale, stringaB);
		printf("la stringa concatenata è: %s\n", stringaFinale);
		fprintf(fileOut, "%s\n", stringaFinale);
		strcpy(stringaA, "");
		strcpy(stringaB, "");
		strcpy(stringaFinale, "");
	}
	*/

	for(int i=0; i<N_PAROLE; i++){
		fscanf(fileA, "%s\n", stringaA);
			for(int j=0; j<N_PAROLE; j++){
			fscanf(fileB, "%s\n", stringaB);
			strcat(stringaFinale, stringaA);
			strcat(stringaFinale, stringaB);
			printf("la stringa concatenata è: %s\n", stringaFinale);
			fprintf(fileOut, "%s\n", stringaFinale);
			strcpy(stringaB, "");
			strcpy(stringaFinale, "");
			}
		rewind(fileB);
		strcpy(stringaA, "");
	}
	
	
	fclose(fileA);
	fclose(fileB);
	fclose(fileOut);
	return 0;
}
