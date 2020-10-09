#include<stdio.h>
#include<stdlib.h>

struct TDato{
	int num;
	char articulo[80];
	int cant;
	float precio;
};

void cascaron();
void alta();
void baja();
void consultas();
void cambios();

int main(){
	int op;
	
	do{
		printf(" 	MENU DE OPCIONES \n");
		printf("0.-Cascaron\n");
		printf("1.-Alta\n");
		printf("2.-Baja\n");
		printf("3.-Consultas\n");
		printf("4.-Cambios\n");
		printf("5.-Salir\n");
		scanf("%i",&op);
		switch(op){
			case 0:
				cascaron();
				break;
			case 1:
				alta();
				break;
			case 2:
				baja();
				break;
			case 3:
				consultas();
				break;
			case 4:
				cambios();
				break;
			case 5:
				printf("Gracias por utilizar la base de datos\n");
				break;
			default:
				printf("Opcion invalida \nIntente de nuevo\n");
				break;
		}
	}while (op!=5);
	
	
}

void cascaron(){
	TDato registro, blanco={0," ",0,0};
	FILE *pf;
	if((pf=fopen("tienda.dat", "wb+"))==NULL){
		printf("Error de apertura\n");
		exit(1);
	}
	
	for(int i=0;i<10;i++){
		fwrite(&blanco, sizeof(TDato), 1, pf);
	}
	fclose(pf);
}

void alta(){
	TDato registro, blanco={0," ",0,0};
	FILE *pf;
	int op;
	if((pf=fopen("tienda.dat", "r+"))==NULL){
		printf("Error de apertura\n");
		exit(1);
	}
	
	do{
		printf("Numero de registro a almacenar 1-10\n");
		scanf("%i",&registro.num);
		fseek(pf,sizeof(TDato)*(registro.num-1),SEEK_SET);
		printf("Articulo\n");
		fflush(stdin);
		gets(registro.articulo);
		printf("Cantidad \n");
		scanf("%i",&registro.cant);
		printf("Precio\n");
		scanf("%f",&registro.precio);
		fwrite(&registro,sizeof(TDato),1,pf);
		printf("Otro registro 0=No\n");
		scanf("%i",&op);
	}while(op!=0);
	fclose(pf);
}

void baja(){
	TDato registro, blanco={0," ",0,0};
	FILE *pf;
	int op,ref;
	if((pf=fopen("tienda.dat", "r+"))==NULL){
		printf("Error de apertura\n");
		exit(1);
	}
	
	do{
		printf("Numero de registro a eliminar 1-10\n");
		scanf("%i",&ref);
		fseek(pf,sizeof(TDato)*(ref-1),SEEK_SET);
		fwrite(&blanco,sizeof(TDato),1,pf);
		printf("Otra baja 0=No\n");
		scanf("%i",&op);
	}while(op!=0);
	fclose(pf);
}

void consultas(){
	TDato registro, blanco={0," ",0,0};
	FILE *pf;
	int op,ref;
	if((pf=fopen("tienda.dat", "r+"))==NULL){
		printf("Error de apertura\n");
		exit(1);
	}
	
	do{
		printf("Numero de registro a consultar 1-10\n");
		scanf("%i",&ref);
		fseek(pf,sizeof(TDato)*(ref-1),SEEK_SET);
		fread(&registro,sizeof(TDato),1,pf);
		printf("\nRegistro consultado\n");
		printf("Numero de registro %i\n",registro.num);
		printf("Articulo %s\n",registro.articulo);
		printf("Cantidad de articulos %i\n",registro.cant);
		printf("Precio %.2f\n",registro.precio);
		printf("Otra consulta 0=No\n");
		scanf("%i",&op);
	}while(op!=0);
	fclose(pf);
}

void cambios(){
	TDato registro, blanco={0," ",0,0};
	FILE *pf;
	char res;
	int op,ref,con;
	if((pf=fopen("tienda.dat", "r+"))==NULL){
		printf("Error de apertura\n");
		exit(1);
	}
	
	do{
		printf("Numero de registro a cambiar 1-10\n");
		scanf("%i",&ref);
		fseek(pf,sizeof(TDato)*(ref-1),SEEK_SET);
		fread(&registro,sizeof(TDato),1,pf);
		printf("\nRegistro a cambiar\n");
		printf("Numero de registro %i\n",registro.num);
		printf("Articulo %s\n",registro.articulo);
		printf("Cantidad de articulos %i\n",registro.cant);
		printf("Precio %.2f\n",registro.precio);
		printf("Este es el dato que quieres cambiar?[S/n]\n");
		scanf("%s",&res);
		if(res=='s' || res=='S'){
			printf("Cual es el dato que quieres cambiar?\n");
			printf("1.-Articulo\n");
			printf("2.-Cantidad\n");
			printf("3.-Precio\n");
			scanf("%i",&con);
			switch(con){
				case 1:
					printf("Dame el nuevo articulo\n");
					fflush(stdin);
					gets(registro.articulo);
					break;
				case 2: 
					printf("Dame la nueva cantidad\n");
					scanf("%i",&registro.cant);
					break;
				case 3:
					printf("Dame el nuevo precio\n");
					scanf("%f",&registro.precio);
					break;
			}
		}
		printf("Otra consulta 0=No\n");
		scanf("%i",&op);
	}while(op!=0);
	fclose(pf);
}
