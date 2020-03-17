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


// defines maximum string length
#define SIZE 200


// receives a char and prints out its integer value according to the problem description, considering that
// A is value 0 and so on
int chartoint(char ch)
{
	//subtracts the ASCII code from the first character (A) till the last (Z), producing the hash values
	return ch - 'A';
}

// converts a whole line to it's hash value, with the aid of some calls to the above function
int convertstr(char ch[], int linenr)
{
	//variable to store the value through the loop
	int temp = 0 ;
	//control variable for the loop
	int i = 0 ;

	// while the loop hasn't reached the end of the string
	while(ch[i] != '\0')
	{
		//increases the size of the temporary result by the hash value of each character on the string
		temp += chartoint(ch[i]) + i + linenr ;
		i++ ;
	}

	return temp ;
}



int main(void) {

	// stores the number of items (outer loop)
	int countitem ;

	// file handling
	FILE *fptr;
	fptr = fopen("/Users/pvgmenegasso/eclipse-workspace/Array Hash/Debug/input.txt","r");

	//scans the first line of the document
	fscanf(fptr, "%d", &countitem) ;

	// stores the number of lines for the current item
	int countlines ;

	//tests the function for the two example cases
	printf("%d", convertstr("CBA")) ;
	printf("\n%d", convertstr("DDD")) ;

	// buffer to read lines
	char buff[SIZE] ;

	// final hash value to return for each item
	int hash = 0 ;

	//
	for(int i = 0 ; i<countitem ; i++)
	{

		hash = 0 ;

		fscanf(fptr, "%d", &countlines) ;

		for(int j = 0 ; j<countlines ; j++)
		{
			fscanf(fptr, "%s", buff) ;
			hash += convertstr(buff, j)  ;
			printf("\n  conteudo linha: %s", buff) ;
			printf("\n  valor hash: %d", hash) ;
		}

		printf("\n  final hash: %d", hash) ;
	}


	printf("\n%d", countitem) ;
	printf("\n%d", countlines) ;
	return EXIT_SUCCESS;
}
