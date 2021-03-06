/*	Numeros aleatorios sin repetir para dar los turnos a la computadora en el juego de batalla naval.
	Este programa da 100 turnos diferentes a la computadora con el fin de cubrir todas las posiciones 
	disponibles en el tablero y sin repetir.	*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define falso 0 
#define verdadero 1

int verifica( int aleatorio[][10] , int col , int fil , int num ) //función para evitar que se repita el valor en la matriz
{
	for( fil = 0 ; fil < 10 ; fil++ )
	{
		for( col = 0 ; col < 10 ; col++ )
		{
			if( num == aleatorio[col][fil] )
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
	int col , fil , num,contador=0;
	srand(time(NULL));
	for( fil = 0 ; fil < 10 ; fil ++)
	{
		for( col = 0 ; col < 10 ; col++ )
		{
			num = 1 + rand()%100;
			while( verifica( aleatorio , 10 , 10 , num ) == falso)
			{
				num = 1 + rand()%100;
			}
			aleatorio[col][fil] = num;
		}
	}
	for( fil = 0 ; fil < 10 ; fil++ )
	{
		printf("\n");
		for( col = 0 ; col < 10 ; col++ )
		{
			printf("\t%d",aleatorio[col][fil]);
		}
	}
	while(contador<=100)
	{
		contador++;
		for( fil = 0 ; fil < 10 ; fil++ )
		{
			
			for( col = 0 ; col < 10 ; col++ )
			{
				if(contador==aleatorio[col][fil])
				{
					printf("\nTurno [%d] -> Columna[%d] , Fila[%d]",contador,col+1,fil+1);
				}
			}
	}	
	}
		return 0;
}
