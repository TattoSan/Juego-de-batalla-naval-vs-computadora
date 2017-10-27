/*Juego de batalla naval contra la computadora.
Puntos a tomar en cuenta:
1-.Existirán 2 tableros, uno para la computadora y otro para el usuario (completado)
2-.Los tableros serán de 10x10 (completado)
3-.La computadora jugará con números aleatorios definidos por la misma (completado)
4-.La computadora acomodará barcos aleatorios los cuales estarán definidos en los ultimos 20 tiros de la computadora dando fin al juego (completado)
5-.El usuario acomodará sus barcos (completado)
6-.Se limitará el tamaño de los barcos de dimension 1x1 (completado)
7-.Se jugará por turnos, si uno de los dos atina a una parte de un barco éste sigue tirando (completado)
8-.Cada vez que el usuario o la computadora tire se marcará en el tablero una X (completado)
9-.Ganará el primero que destruya los 20 barcos (completado) */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define falso 0
#define verdadero 1
#define muerto 2

void inimatriz(int matriz[][10]);
void matriz_aleatoria(int aleatorio[][10]);
int verifica( int aleatorio[][10] , int col , int fil , int num );
int dado();
void posicion(int matriz[][10]);
void tablero_usuario(int matriz[][10]);
void tablero_pc(int matrizpc[][10]);
void escribir(int matriz[][10]);
void escribirpc(int aleatorio[][10],int matrizpc[][10]);
int juego(int matriz[][10],int aleatorio[][10],int matrizpc[][10],int ladodado, int contadorusuario, int contadorpc,int contadorturno);

int main()
{
	int matriz[10][10];
	int matrizpc[10][10];
	int aleatorio[10][10];
	int tira;
	int contadorusuario=0;
	int contadorpc=0;
	int contadorturno=1;
	system("color 9A");
	int ladodado;
	inimatriz(matriz); //argumento que inicializa todos los valores de la matriz del usuario en 0(falso)
	inimatriz(matrizpc); //argumento que inicializa todos los valores de la matriz de la pc en 0(falso)


	printf("\t\tBienvenido al juego de batalla naval\n");
	printf("Para empezar debes posicionar veinte barcos de dimensi%cn 1x1 en el tablero\n",162);
	system("pause");
	system("cls");
	posicion(matriz);
	ladodado = dado();
	matriz_aleatoria(aleatorio);
	escribirpc(aleatorio,matrizpc);
	juego(matriz,aleatorio,matrizpc,ladodado,contadorusuario,contadorpc,contadorturno);
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
	printf("\n\t\t\tEl dado cay%c: %d",162,r);
				switch(op)
				{
					case 1:
						if(r%2==0)
						{
							printf("\t¡Tu tiras primero!\n");
							system("pause");
							return verdadero;
						}
						else
						{
							printf("\t¡Tira primero la computadora!\n");
							system("pause");
							return falso;
						}
						break;
					case 2:
						if(r%2==1)
						{
							printf("\t¡Tu tiras primero!\n");
							system("pause");
							return verdadero;
						}
						else
						{
							printf("\t¡Tira primero la computadora!\n");
							system("pause");
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
	int i,j;
	printf("TABLERO USUARIO\nCOLUMNA\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\nFILA");
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
		
			}
		}
	}
}
void posicion(int matriz[][10])//Aqui ponemos los barcos en el mapa
{
	
	int i;
	system("cls");
	tablero_usuario(matriz);
	for(i=1;i<=20;i++)
	{
		
		printf("\nBarco n%cmero [%d] (COLUMNA,FILA):",163,i);
		escribir(matriz);
		
	}
}
void escribir(int matriz[][10])
{
	
	int colusu,filusu;
	scanf("%d,%d",&colusu,&filusu);
	
	colusu--;
	filusu--;
		if(matriz[colusu][filusu]==verdadero)
		{
		
			printf("\n\nElige otra posici%cn (COLUMNA,FILA):",162);
			escribir(matriz);
		}
		else
		{
			matriz[filusu][colusu]=verdadero;
			system("cls");
			tablero_usuario(matriz);
		}	
	
}
void escribirpc(int aleatorio[][10],int matrizpc[][10]) //escribe en la matriz de la pc los 10 barcos
{
	int i,j;
	int contador=0;
	while(contador<=100) //opcion para poner los turnos y colocar los barcos aleatorios en la pc
	{
		contador++;
		for( i = 0 ; i < 10 ; i++ )
		{
			
			for( j = 0 ; j < 10 ; j++ )
			{
				if(contador==aleatorio[i][j])
				{
				//	printf("\nTurno [%d] -> Columna[%d] , Fila[%d]",contador,i+1,j+1);
					if(contador>80)
					{	
						matrizpc[i][j]=verdadero;
					}
				}
			}
		}	
	}
}
int juego(int matriz[][10],int aleatorio[][10],int matrizpc[][10],int ladodado, int contadorusuario, int contadorpc,int contadorturno)
{
int col,fil;
int contador=0;
	if(ladodado == verdadero)
	{	
		system("cls");	
		tablero_usuario(matriz);
		printf("\n---------------------------------------------------------------------------------\n");
		tablero_pc(matrizpc);
		printf("\nTira la posici%cn (X,Y):",162);
		scanf("%d,%d",&col,&fil);
		col--;
		fil--;
		if(matrizpc[fil][col]==verdadero)
		{
			matrizpc[fil][col]=muerto;
			system("cls");
			tablero_pc(matrizpc);
			printf("\nHaz destruido el barco n%cmero [%d]\n",163,contadorusuario+1);
			contadorusuario++;
			
			system("pause");
			if(contadorusuario==20)
			{
				printf("\nLe haz ganado a la computadora!\n");
			}
			else
			{
			juego(matriz,aleatorio,matrizpc,ladodado,contadorusuario,contadorpc,contadorturno);
			}
		}
		else
		{
			matrizpc[fil][col]=muerto;
			system("cls");
			tablero_pc(matrizpc);
			printf("\nHaz fallado, le toca tirar a la pc\n");
			ladodado=falso;
			system("pause");
			
			juego(matriz,aleatorio,matrizpc,ladodado,contadorusuario,contadorpc,contadorturno);
		}
	}
	
	else
	{
		system("cls");
		tablero_usuario(matriz);
		printf("\n---------------------------------------------------------------------------------\n");
		tablero_pc(matrizpc);
		while(ladodado==falso && contadorpc!=20) //opcion para poner los turnos y colocar los barcos aleatorios en la pc
		{
			contador++;
			for( fil = 0 ; fil < 10 ; fil++ )
			{
				for( col = 0 ; col < 10 ; col++ )
				{
					if(contador==aleatorio[fil][col])
					{
							if(contador==contadorturno)
							{
								if(matriz[fil][col]==falso)
								{
								system("cls");
								matriz[fil][col]=muerto;
								tablero_usuario(matriz);
								printf("\nTurno [%d] -> Columna[%d] , Fila[%d]\n",contador,col+1,fil+1);
								printf("\nLA COMPUTADORA HA FALLADO, TE TOCA TIRAR\n");
								contadorturno++;
								ladodado=verdadero;
								
								system("pause");
								}
								else
								{
								system("cls");
								matriz[fil][col]=muerto;
								tablero_usuario(matriz);
								printf("\nTurno [%d] -> Columna[%d] , Fila[%d]\n",contador,col+1,fil+1);
								printf("\nLA COMPUTADORA TE HA DESTRUIDO BARCO NUMERO [%d]\n",contadorpc+1);
								contadorturno++;
								ladodado=falso;
								
								contadorpc++;
								system("pause");
								}
							}
							

					}		
				}
			}
			
		}
		if(contadorpc==20)
		{
			printf("\nLA COMPUTADORA TE HA GANADO");
		}
		else
		{
		juego(matriz,aleatorio,matrizpc,ladodado,contadorusuario,contadorpc,contadorturno);
		}
	}
}
void tablero_pc(int matrizpc[][10])
{
	int i,j;
	printf("TABLERO PC\nCOLUMNA\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\nFILA");
	for(i=0;i<10;i++)
	{
	printf("\n%d",i+1);
		for(j=0;j<10;j++)
		{
			switch(matrizpc[i][j])
			{
				case falso:
					printf("\t-");
					break;
				case verdadero:		
					printf("\t-");
					break;
				case muerto:
					printf("\tX");
					break;
		
			}
		}
	}
}
