/*
 * ConcatenazioneStringhe.c
 * 
 * Copyright 2018 alexmik <alexmik@alexmik_archlinux>
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LENGTH 20 

char* concatena(char *nomeFileA, char *nomeFileB, char *nomeFileOut) {
	FILE *listaA;
	listaA = fopen(nomeFileA, "r");
	FILE *listaB;
	listaB = fopen(nomeFileB, "r");
	FILE *listaOut;
	listaOut = fopen(nomeFileOut, "a+");
	
	//char *stringaA = malloc(sizeof(char) MAX_STR_LENGTH);
	char stringaA[MAX_STR_LENGTH];
	fscanf(listaA, "%s", stringaA);
	printf("letta stringa dal file A: %s", stringaA);

	//char *stringaB = malloc(sizeof(char) MAX_STR_LENGTH);
	char stringaB[MAX_STR_LENGTH];
	fscanf(listaB, "%s", stringaB);
	printf("letta stringa dal file B: %s", stringaB);
	int strgLength = ( (strlen(stringaA))+(strlen(stringaB)) + 1);
	char *strg = malloc(sizeof(char) * strgLength );		//alloca porzione di memoria per contenere la stringa di massima lunghezza la somma delle due in input
	//char strg[MAX_STR_LENGTH];
	strcpy ( strcat(stringaA, stringaB), strg );
	fprintf(listaOut, "%s", strg);

	fclose(listaA);
	fclose(listaB);
	fclose(listaOut);

	return strg;
}

#include <stdio.h>

int main() {
	char *stringaFinale;
	char lA[]="listaA.txt";
	char lB[]="listaB.txt";
	char lO[]="listaOut.txt";
	strcpy( stringaFinale, concatena(lA, lB, lO) );
	printf("%s", stringaFinale);
	return 0;
}
