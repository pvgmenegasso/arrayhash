/*
 ============================================================================
 Name        : Array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 200


int chartoint(char ch)
{
	return ch - 'A';
}

int convertstr(char ch[])
{
	int temp = 0 ;
	int i = 0 ;
	while(ch[i] != '\0')
	{
		temp += chartoint(ch[i]) + i ;
		i++ ;
	}

	return temp ;
}



int main(void) {

	int countitem ;
	FILE *fptr;
	fptr = fopen("/Users/pvgmenegasso/eclipse-workspace/Array Hash/Debug/input.txt","r");
	fscanf(fptr, "%d", &countitem) ;
	int countlines ;

	printf("%d", convertstr("CBA")) ;
	printf("\n%d", convertstr("DDD")) ;

	char buff[SIZE] ;

	int hash = 0 ;

	for(int i = 0 ; i<countitem ; i++)
	{

		hash = 0 ;

		fscanf(fptr, "%d", &countlines) ;

		for(int j = 0 ; j<countlines ; j++)
		{
			fscanf(fptr, "%s", buff) ;
			hash += convertstr(buff) + j ;
			printf("\n  conteudo linha: %s", buff) ;
			printf("\n  valor hash: %d", hash) ;
		}

		printf("\n  final hash: %d", hash) ;
	}


	printf("\n%d", countitem) ;
	printf("\n%d", countlines) ;
	return EXIT_SUCCESS;
}
