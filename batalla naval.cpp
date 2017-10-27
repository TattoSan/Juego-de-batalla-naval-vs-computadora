/*Juego de batalla naval contra la computadora.
Puntos a tomar en cuenta:
1-.Existirán 2 tableros, uno para la computadora y otro para el usuario
2-.Los tableros serán de 10x10 (completado)
3-.La computadora jugará con números aleatorios definidos por la misma (completado)
4-.La computadora acomodará barcos aleatorios los cuales estarán definidos en los ultimos 20 tiros de la computadora dando fin al juego.
5-.El usuario acomodará sus barcos (completado)
6-.Se limitará el tamaño de los barcos de dimension 1x1 (
7-.Se jugará por turnos, si uno de los dos atina a una parte de un barco éste sigue tirando
8-.Cada vez que el usuario o la computadora tire se marcará en el tablero una X
9-.Ganará el primero que destruya los 20 barcos*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define falso 0
#define verdadero 1
#define muerto 2

void inimatriz(int matriz[][10]);
void matriz_aleatoria(int aleatorio[][10]);
int verifica( int aleatorio[][10] , int col , int fil , int num );
int dado();
void posicion(int matriz[][10]);
void tablero_usuario(int matriz[][10]);
void escribir(int matriz[][10], int i);
void juego(int matriz[][10],int aleatorio[][10],int matrizpc[][10],int tira);

int main()
{
	int matriz[10][10];
	int matrizpc[10][10];
	int aleatorio[10][10];
	int tira;
	
	int ladodado;
	inimatriz(matriz); //argumento que inicializa todos los valores de la matriz del usuario en 0(falso)
	inimatriz(matrizpc); //argumento que inicializa todos los valores de la matriz de la pc en 0(falso)


	printf("\t\tBienvenido al juego de batalla naval\n");
	printf("Para empezar debes posicionar veinte barcos de dimensi%cn 1x1 en el tablero\n",162);
	system("pause");
	 
	posicion(matriz);
	ladodado = dado();
	matriz_aleatoria(aleatorio);
	
	return 0;
	
}
void inimatriz(int matriz[][10]) //inicializa todos los valores de la matriz del usuario en 0
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			matriz[i][j]=0;
		}
	}
	
}
void matriz_aleatoria(int aleatorio[][10]) //Empieza la asignación de la matriz aleatoria para determinar los tiros de la computadora
{
	
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
	
}

int verifica( int aleatorio[][10] , int col , int fil , int num ) //función para evitar que se repita el valor en la matriz de los tiros de la computadora
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

int dado() //Función para ver quien tira primero, si el usuario o la computadora
{
	int r,op;
	srand(time(NULL));
	r=1+rand()%(6-1);
	printf("\n\n\t\tPara tirar primero elige si tu numero es par o impar (1-PAR/2-IMPAR):");
	scanf("%d",&op);
	printf("\n\t\t\tEl dado cay%c %d\n",162,r);
				switch(op)
				{
					case 1:
						if(r%2==0)
						{
							printf("\t\t¡Tu tiras primero!\n");
							return verdadero;
						}
						else
						{
							printf("\t\t¡Tira primero la computadora!\n");
							return falso;
						}
						break;
					case 2:
						if(r%2==1)
						{
							printf("\t\t¡Tu tiras primero!\n");
							return verdadero;
						}
						else
						{
							printf("\t\t¡Tira primero la computadora!\n");
							return falso;
						}
						break;
					default:
						printf("\t\tERROR!!");
						dado();
				}

}
void tablero_usuario(int matriz[][10]) //imprime la matriz del usuario en 3 casos, falso=-,verdadero=O y muerto=X
{
		
	system("cls");
	int i,j;
	printf("COLUMNA\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\nFILA");
	for(i=0;i<10;i++)
	{
	printf("\n%d",i+1);
		for(j=0;j<10;j++)
		{
			switch(matriz[i][j])
			{
				case falso:
					printf("\t-");
					break;
				case verdadero:		
					printf("\tO");
					break;
				case muerto:
					printf("\tX");
					break;
		
			}
		}
	}
}
void posicion(int matriz[][10])//Aqui ponemos los barcos en el mapa
{
	
	int i;
	
	tablero_usuario(matriz);
	for(i=1;i<=20;i++)
	{
		
		printf("\nBarco n%cmero [%d] (COLUMNA,FILA):",163,i);
		escribir(matriz,i);
	}
}
void escribir(int matriz[][10], int i)
{
	int colusu,filusu;
	scanf("%d,%d",&colusu,&filusu);
		if(matriz[colusu-1][filusu-1]==verdadero)
		{
		
			printf("\n\nElige otra posici%cn (COLUMNA,FILA):",162);
			escribir(matriz,i);
		}
		else
		{
			matriz[filusu-1][colusu-1]=verdadero;
			tablero_usuario(matriz);
		}	
}
