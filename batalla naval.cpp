/*Juego de batalla naval contra la computadora.
Puntos a tomar en cuenta:
1-.Existirán 2 tableros, uno para la computadora y otro para el usuario
2-.Los tableros serán de 10x10
3-.La computadora jugará con números aleatorios definidos por la misma
4-.La computadora acomodará barcos aleatorios
5-.El usuario acomodará sus barcos
6-.Se limitará el tamaño de los barcos de dimension 2x1*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define falso 0
#define verdadero 1
#define muerto 2
void inimatriz(int matriz[][10]);
void matriz_aleatoria();
int verifica( int aleatorio[][10] , int col , int fil , int num );
int dado();
void posicion();
void tablero_usuario(int matriz[][10]);
int matrizevaluada(int matriz[][10],int filusu,int colusu);

int main()
{
	matriz_aleatoria();

	printf("\t\tBienvenido al juego de batalla naval\n");
	printf("Para empezar debes posicionar diez barcos de dimensi%cn 2x1 en el tablero\n",162);
	system("pause");
//	posicion();
	dado();
	return 0;
	
}
void inimatriz(int matriz[][10])
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
void matriz_aleatoria() //Empieza la asignación de la matriz aleatoria
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

}

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

int dado()
{
	int r,op;
	srand(time(NULL));
	r=1+rand()%(6-1);
	printf("\n\n\t\tPara tirar primero elige si tu numero es par o impar (1-PAR/2-IMPAR):");
	scanf("%d",&op);
				switch(op)
				{
					case 1:
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
					case 2:
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
					default:
						printf("\t\tERROR!!");
						dado();
				}

}
void tablero_usuario(int matriz[][10])
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
void posicion()
{
	
	int matriz[10][10],i,j,k,valor,colusu,filusu;
	inimatriz(matriz);
	tablero_usuario(matriz);
	for(i=0;i<10;i++)
	{
		
		printf("\nBarco n%cmero [%d] (COLUMNA,FILA):",163,i+1);
		scanf("%d,%d",&colusu,&filusu);
		matriz[filusu-1][colusu-1]=verdadero;
		matrizevaluada(matriz,filusu,colusu);
		tablero_usuario(matriz);
	}
}
int matrizevaluada(int matriz[][10],int filusu,int colusu)
{
		if(filusu==1 && colusu==1)
		{
			printf("Puede elegir [%d,%d] o [%d,%d] para la otra parte del barco:",colusu+1,filusu,colusu,filusu+1);//
			scanf("%d,%d",&colusu,&filusu);
			matriz[filusu-1][colusu-1]=verdadero;
			return 0;
		}
		if(filusu==1 && (colusu==2 || colusu==3 || colusu==4 || colusu==5 || colusu==6 || colusu==7 || colusu==8 || colusu==9))	
		{
				
			printf("Puede elegir [%d,%d] o [%d,%d] o [%d,%d] para la otra parte del barco:",colusu+1,filusu,colusu-1,filusu,colusu,filusu+1);//
			scanf("%d,%d",&colusu,&filusu);
			matriz[filusu-1][colusu-1]=verdadero;
			return 0;
		}
		if(filusu==1 && colusu==10)
		{
			printf("Puede elegir [%d,%d] o [%d,%d] para la otra parte del barco:",colusu-1,filusu,colusu,filusu+1);//
			scanf("%d,%d",&colusu,&filusu);
			matriz[filusu-1][colusu-1]=verdadero;
			return 0;
		}
		if((filusu==2 || filusu==3 || filusu==4 || filusu==5 || filusu==6 || filusu==7 || filusu==8 || filusu==9) && colusu==1)
		{
				
			printf("Puede elegir [%d,%d] o [%d,%d] o [%d,%d] para la otra parte del barco:",colusu,filusu-1,colusu+1,filusu,colusu,filusu+1);//
			scanf("%d,%d",&colusu,&filusu);
			matriz[filusu-1][colusu-1]=verdadero;
			return 0;
		}
		if(filusu==10 && colusu==1)
		{
			printf("Puede elegir [%d,%d] o [%d,%d] para la otra parte del barco:",colusu+1,filusu,colusu,filusu-1);//
			scanf("%d,%d",&colusu,&filusu);
			matriz[filusu-1][colusu-1]=verdadero;
			return 0;
		}
			if(filusu==10 && (colusu==2 || colusu==3 || colusu==4 || colusu==5 || colusu==6 || colusu==7 || colusu==8 || colusu==9))	
		{
				
			printf("Puede elegir [%d,%d] o [%d,%d] o [%d,%d] para la otra parte del barco:",colusu+1,filusu,colusu-1,filusu,colusu,filusu-1);//
			scanf("%d,%d",&colusu,&filusu);
			matriz[filusu-1][colusu-1]=verdadero;
			return 0;
		}
		if(filusu==10 && colusu==10)
		{
			printf("Puede elegir [%d,%d] o [%d,%d] para la otra parte del barco:",colusu-1,filusu,colusu,filusu-1);//
			scanf("%d,%d",&colusu,&filusu);
			matriz[filusu-1][colusu-1]=verdadero;
			return 0;
		}
		if((filusu==2 || filusu==3 || filusu==4 || filusu==5 || filusu==6 || filusu==7 || filusu==8 || filusu==9) && colusu==10)
		{
				
			printf("Puede elegir [%d,%d] o [%d,%d] o [%d,%d] para la otra parte del barco:",colusu,filusu-1,colusu-1,filusu,colusu,filusu+1);//
			scanf("%d,%d",&colusu,&filusu);
			matriz[filusu-1][colusu-1]=verdadero;
			return 0;
		}
		if((filusu==2 || filusu==3 || filusu==4 || filusu==5 || filusu==6 || filusu==7 || filusu==8 || filusu==9)&&(colusu==2 || colusu==3 || colusu==4 || colusu==5 || colusu==6 || colusu==7 || colusu==8 || colusu==9))
		{
			printf("Puede elegir [%d,%d] o [%d,%d] o [%d,%d] o [%d,%d]:",colusu+1,filusu,colusu-1,filusu,colusu,filusu+1,colusu,filusu-1);
			scanf("%d,%d",&colusu,&filusu);
			matriz[filusu-1][colusu-1]=verdadero;
			return 0;
		}
}





