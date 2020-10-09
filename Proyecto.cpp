#include<stdio.h>
#include<stdlib.h>

struct datos{
	int ID;
	char cb[10];
	char Nombre[20];
	int precio;
	char descripcion[100];
	int cantidad;
	char proveedor[30];
};

void cascaron();
void inventario();
void consulta();
void altas();

int main ()
{
	mein:
	int op;

	do{
	printf("0:Crear Cascaron (Se Perderan los datos si es que ya este creado uno).\n");
	printf("1:Inventario.\n");
	printf("3:Salir.\n");
	scanf("%i",&op);
	switch (op)
	{
		case 0:
			cascaron();
			break;
		case 1:
			inventario();
			goto mein;
			break;
	}


	}while(op!=3);
}

void cascaron()
{
	int cascaron,i;
	datos registro, blanco={0,"","",0,"",0,""};
	FILE *file;
	if((file=fopen("inventario.dat", "wb+"))==NULL){
		printf("Error de apertura");
		exit(1);
	}
	printf("Que tan grande quieres el cascaron?");
	scanf("%i",&cascaron);
	for(i=0;i<cascaron;i++)
	{
		fwrite(&blanco, sizeof(datos),1,file);
	}
	fclose(file);
}

void inventario()
{
	int op;
	printf("1:Agregar un nuevo Articulo\n");
	printf("2:Buscar un Articulo\n");
	printf("3:Regresar\n");
	scanf("%i",&op);
	switch(op)
	{
		case 1:
			altas();
			break;
		case 2:
			consulta();
			break;
		case 3:
			//return;
			break;
	}
}

void altas()
{
	datos registro,aux,blanco={0,"","",0,"",0,""};
	FILE * file;
	int op;
	if((file=fopen("inventario.dat", "w+"))==NULL){
		printf("ERROR de apertura");
		exit(1);
	}
	printf("Numero de registro donde almacenar:");
	scanf("%i",&registro.ID);
		fseek(file,sizeof(datos)*(registro.ID),SEEK_SET);
		fread(&registro,sizeof(datos),1,file);
		printf("Introduzca Codigo de Barras:\n");
		fflush(stdin);
		gets(registro.cb);
		printf("Introduzca Nombre de Archivo:\n");
		fflush(stdin);
		gets(registro.Nombre);
		printf("Introduzca el Precio Unitario\n");
		scanf("%i",&registro.precio);
		printf("Introduzca breve descripcion:\n");
		fflush(stdin);
		gets(registro.descripcion);
		printf("Introduzca Cantidad:\n");
		scanf("%i",&registro.cantidad);
		printf("Introduzca Proveerdor:\n");
		fflush(stdin);
		gets(registro.proveedor);
		fwrite(&registro,sizeof(datos),1,file);
	fclose(file);
}

void consulta()
{
	datos registro;
	FILE * file;
	int op,ref;
	if((file=fopen("inventario.dat", "r+"))==NULL)
	{
		printf("Error de apertura");
		//exit(1);
	}
	printf("Numero de registro a consultar:");
	scanf("%i",&ref);
	//while(ref!=0){
		fseek(file,sizeof(datos)*(ref),SEEK_SET);
		fread(&registro,sizeof(datos),1,file);
		printf("\nRegistro Consultado\n");
		printf("ID:%i\n",registro.ID);
		printf("Codigo De Barras:%s\n",registro.cb);
		printf("Nombre:%s\n",registro.Nombre);
		printf("Precio:%i\n",registro.precio);
		printf("Descripcion:%s\n",registro.descripcion);
		printf("Cantidad:%i\n",registro.cantidad);
		printf("Proveedor:%s\n",registro.proveedor);
	//}
	fclose(file);
}
