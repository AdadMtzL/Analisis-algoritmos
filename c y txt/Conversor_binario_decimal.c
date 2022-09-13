/**
Instituto Politecnico Nacional
Escuela Superior de cómputo

Urbina Garcia ALan Israel
Martinez Luna Adad Marcel
*/
#include<stdio.h>
#include<math.h>
#include<time.h>
void main()
{
	int cont=0;
	int nbits=0;cont++;
	srand(time(0));
	printf("Indique la cantidad de bits a manejar \n");cont++;
	scanf("%d",&nbits);cont++;
	int Num1[nbits],Num2[nbits],i,Num3[nbits],j=0;
	//llenado del arreglo 1
	cont++;
	for(i=0;i<nbits;i++)
	{
		Num1[i]=rand()%2;cont++;
	}
	//llenado del arreglo 2
	cont++;
	for(i=0;i<nbits;i++)
	{
		Num2[i]=rand()%2;cont++;
	}
	//Aqui ocurre el and 
	cont++;
	for(i=0;i<nbits;i++)
	{
		if(Num1[i]==1 && Num2[i]==1)
		{
			Num3[i]=1;cont++;
		}
		else
		{
			Num3[i]=0;cont++;
		}
	}
	//Aqui ocurre la conversión de binario a decimal
	cont++;
	for(i=nbits-1;i>=0;i--)
	{
		j=j+(Num3[i]*pow(2,i));cont++;
	}
	//Se imprime el valor en decimal
	printf("\n Valor final de la operación en decimal %d\n",j);cont++;
	printf("La cantidad de pasos realizados fue de %d",cont);
}

