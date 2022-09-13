#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
* Instituto Politécnico Nacional	
* Escuela Superior de Cómputo	
* Martinez Luna Adad Marcel
* Urbina García Alan Israel
**/

int Nodos;

/**
*@brief Función que imprime la matriz de adyacencia de manera bonita
*
*@param mat_nodos
*@return
*/
void ImprimirMatriz(int mat_nodos[Nodos][Nodos])
{
	int i,j;
	printf("\t");
	for(i=0;i<Nodos;i++)
	{
		printf("%d \t",i+1);
	}
	putchar('\n');
	for(i=0;i<Nodos;i++)
	{
		printf("_________");
	}
	putchar('\n');
	for(i=0;i<Nodos;i++)
	{	
		printf("%d |\t",i+1);
		for(j=0;j<Nodos;j++)
		{
			if(mat_nodos[i][j]==1)
			{
				printf("%d\t|",mat_nodos[i][j]);
			}
			else
			{
				printf("-\t|");
			}
		}
		putchar('\n');
	}
	putchar('\n');
}

/**
*@brief Función que genera una amtriz de adyacencia aleatoria, puede que falle al gnerar un grafo que cumpla 
*		condiciones para que se calcule el camino hamiltoniano
*
*@param mat_nodos
*@return
*/
void LlenarMatriz(int mat_nodos[Nodos][Nodos])
{
	srand(time(NULL));
	int pasos=0;
	int i,j,con;pasos++;
	for(i=0;i<Nodos;i++)
	{
		for(j=0;j<Nodos;j++)
		{
			if(i==j)
			{
				mat_nodos[i][j]=0;pasos++;
			}
			else
			{
				con=(rand()%25)+1;pasos++;
				if(con%2==1 || con%7==1)
				{
					mat_nodos[i][j]=1;pasos++;
				}
				else
				{
					mat_nodos[i][j]=0;pasos++;
				}
			}
		}
	}
	printf("Pasos funcion LlenarMatriz:\t%d\n",pasos);
}

/**
*@brief Determina si el camino indicado es hamiltoniano
*
*@param mat_nodos
*@param camino_ham
*@return
*/
void VerificacionHamilton(int mat_nodos[Nodos][Nodos],int camino_ham[Nodos])
{
	int pasos=0;
	int i,cont=0,x,y;pasos++;
	for(i=0;i<Nodos-1;i++)
	{
		x=camino_ham[i]-1;pasos++;
		y=camino_ham[i+1]-1;pasos++;
		if(mat_nodos[x][y]!=1)
		{
			cont++;pasos++;
		}
	}
	if(cont==0)
	{
		printf("El camino seleccionado es hamiltoniano\n");pasos++;
		printf("Pasos funcion VerifiacionHamilton:\t%d\n",pasos);
	}
	else
	{
		printf("El camino seleccionado no es hamiltoniano\n");pasos++;
		printf("Pasos funcion VerifiacionHamilton:\t%d\n",pasos);
	}
}


/**
*@brief Función que obtiene el camino hamiltoniano indicado por el usuario
*
*@param sol
*@return
*/
void Camino_Hamil(int sol[Nodos])
{
	int pasos=0;
	int i =0,nodo;pasos++;
	do
	{
		printf("Indique el nodo %d, tome en cuenta que no se repiten \n",i+1);pasos++;
		scanf("%d",&nodo);pasos++;
		sol[i]=nodo;pasos++;
		i++;pasos++;
	}while(i<Nodos);
	printf("Pasos funcion Camino_Hamil:\t%d\n",pasos);
}

/**
*@brief Función que determina que no haya vertices de grado 1 en el grafo si hay uno de estos regresara 0
*
*@param graph
*@return int
*/
int Grado(int graph[Nodos][Nodos])
{
	int pasos=0;
	int grd=0;pasos++;
	int grnds=0;pasos++;
	int i,j;pasos++;
	for(i=0;i<Nodos;i++)
	{
		for(j=0;j<Nodos;j++)
		{
			if(i==j)
			{
				pasos++;//Nada
			}
			else
			{
				if(graph[i][j]==0)
				{
					grd++;pasos++;
					if(grd==Nodos-2)
					{
						grnds++;pasos++;
					}	
				}
			}
		}
		grd=0;pasos++;
	}
	if(grnds==0)
	{
		pasos++;
		printf("Pasos funcion grado:\t%d\n",pasos);
		return 1;
	}
	else
	{
		pasos++;
		return 0;
	}
}


/**
*@brief Función que verifica que haya más de 3 vertices, regresara 0 si es hay menos, 1 si hay 3 o más
*
*@param
*@return int
*/
int CondHamilton()
{
	if(Nodos<3)
	{
		return 0;	
	}
	else
	{
		return 1;
	}
}

/**
*@brief Función principal del programa
*
*@param
*@return
*/
void main()
{
	int cant_nodos,i;
	while(cant_nodos<2)
	{
		printf("Indique una cantidad de nodos para el grafo, el valor tiene que ser mayor a 1\n");
		scanf("%d",&cant_nodos);
	}
	Nodos=cant_nodos;
	int adyacencia[cant_nodos][cant_nodos];
	LlenarMatriz(adyacencia);
	printf("Grafo como matriz de adyacencias\n");
	ImprimirMatriz(adyacencia);
	if(CondHamilton()==1 && Grado(adyacencia)==1)
	{
		printf("El grafo es hamiltoniano\n");
		int solucion_grafo[Nodos];
		Camino_Hamil(solucion_grafo);
		printf("El camino propuesto fue el de\n");
		for(i=0;i<Nodos-1;i++)
		{
			printf("nodo %d a nodo %d\n",solucion_grafo[i],solucion_grafo[i+1]);
		}
		VerificacionHamilton(adyacencia,solucion_grafo);
	}
	else
	{
		printf("El grafo no tiene grado de 2 en cada nodo o vertice como minimo, de no ser así este tiene menos de 3 vertices\n");
	}
}
