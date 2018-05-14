/*
 * ConcatenazioneStringhe.c
 * 
 * Copyright 2018 alexmik <alexmik@alexmik_archlinux>
 * 
 */
#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGHT 20 

char* concatena(char *nomeFIleA, char *nomeFileB) {
	FILE *listaA = fopen(“listaA.txt”, “r”);
	FILE *listaB = fopen(“listaB.txt”, “r”);
	FILE *listaOUT = fopen(“listaOUT.txt”, “a+”);
	
	char *stringaA = malloc(sizeof(char) MAX_STR_LENGHT);
	fscanf(listaA, "%s", &stringaA);
	printf("letta stringa dal file A: %s", stringaA);

	char *stringaB = malloc(sizeof(char) MAX_STR_LENGHT);
	fscanf(listaB, "%s", &stringaB);
	printf("letta stringa dal file B: %s", stringaB);
	
	char *strg = malloc(sizeof(char) * ((strlen(stringaA))+(strlen(stringaB) )) );		//alloca porzione di memoria per contenere la stringa di massima lunghezza la somma delle due in input
	strg = strcat(stringaA, stringaB);
	fprintf(listaOUT, "%s", strg);

	fclose(listaA);
	fclose(listaB);
	fclose(listaOUT);

	return strg;
}

#include <stdio.h>

int main() {
	char *stringaFinale;
	strcpy( stringaFinale, concatena("listaA", "listaB") );
	printf("%s", stringaFinale);
	return 0;
}
