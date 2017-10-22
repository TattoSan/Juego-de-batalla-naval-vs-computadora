/*Numeros aleatorios sin repetir para dar los turnos a la computadora en el juego de batalla naval*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define falso 0
#define verdadero 1

int verifica(int aleatorio[][10],int col, int fil, int num)
{
	for(col=0;col<10;col++)
	{
		for(fil=0;fil<10;fil++)
		{
			if(num==aleatorio[col][fil])
			{
				return falso;
			}
		}
	}
	return verdadero;
}
int main()
{
	
	int aleatorio[10][10];
	int col,fil,num;
	srand(time(NULL));
	for(col=0;col<10;col++)
	{
		for(fil=0;fil<10;fil++)
		{
			num =1+ rand()%100;
			while(verifica(aleatorio,10,10,num)==falso)
			{
				num =1+ rand()%100;
			}
			aleatorio[col][fil]=num;
		}
	}
	for(col=0;col<10;col++)
	{
		printf("\n");
		for(fil=0;fil<10;fil++)
		{
			printf("\t%d",aleatorio[col][fil]);
		}
	}
		return 0;
}
