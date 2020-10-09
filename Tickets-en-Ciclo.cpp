#include<stdio.h>
#include<stdlib.h>

int main ()
{
	FILE * file;
	char cadena[30];
	int i;
	
	for(i=1;i<6;i++){
	sprintf(cadena,"Ticket %i.txt",i);
	file=fopen(cadena, "w");
	}
}
