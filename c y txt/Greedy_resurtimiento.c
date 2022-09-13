#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
*Instituto Politécnico Nacional
*Escuela Superior de Cómputo
*Martinez Luna Adad Marcel
*Urbuna García Alan Israel
*
*/

/**
*@brief Función que implementa el algoritmo greedy, retornara el total de fecas para resurtirse
*
*@param fechas
*@param fechas_res
*@param cantidad
*@param resurt
*@return int
*/
int greedy(int fechas[100],int fechas_res[100],int cantidad,int resurt)
{	
	int i,total=0,temp=0,cont=0;
	for(i=0;i<cantidad;i++)
	{
		if(fechas[i]>resurt+temp)
		{
			fechas_res[total]=fechas[i-1];cont++;
			total++;cont++;
			temp=fechas[i-1];cont++;
		}
		else
		{
			if(fechas[i]==resurt+temp)
			{
				fechas_res[total]=fechas[i];cont++;
				total++;cont++;
				temp=fechas[i];cont++;
			}
		}
		if(i==cantidad-1)
		{
			fechas_res[total]=fechas[i];cont++;
			total++;cont++;
		}
	}
	cont++;
	printf("cantidad de pasos greedy:%d\n",cont);
	return total;
}
void imprimirarreglo(int arreglo[100],int n)
{
	int i,ct=0;
	for(i=0;i<n;i++)
	{
		printf("%d ",arreglo[i]);ct++;
	}
	putchar('\n');ct++;
	//printf("Cantidad de pasos imprimirmatriz:%d\n",ct);
}

/**
*@brief Función que llena el arreglo correspondientes a las fechas, sin embargo este no ordenara los datos.
*
*@param arrego
*@param n
*@return int
*/
void llenararreglo(int arreglo[100],int n)
{
	int i,dia,cont=0;
	for(i=0;i<n;i++)
	{
		printf("indique el dia de apertura no: %d\n",i+1);cont++;
		scanf("%d",&dia);cont++;
		arreglo[i]=dia;cont++;
	}
	//printf("cantidad de pasos llenararreglo %d\n",cont);
}

/**
*@brief Función principal del programa, esta hace las llamadas a las demás funciones existentes
*
*@param 
*@return int
*/
int main()
{
	int cantidad,resurtimiento,cant2;
	printf("Indique la cantidad de fechas en las que abre la tienda\n");
	scanf("%d",&cantidad);
	printf("Indique cada cuanto tiempo se tendra que resurtir\n");
	scanf("%d",&resurtimiento);
	int fechas[cantidad],fechas_res[cantidad];
	llenararreglo(fechas,cantidad);
	printf("Fechas de apertura\n");
	imprimirarreglo(fechas,cantidad);
	cant2=greedy(fechas,fechas_res,cantidad,resurtimiento);
	printf("Fechas para resurtirse\n");
	imprimirarreglo(fechas_res,cant2);
	return 0;	
}
