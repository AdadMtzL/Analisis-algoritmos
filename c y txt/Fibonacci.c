/**
		Instituto Polit�cnico Nacional
		Escuela Superior de C�mputo
				Practica 2
		Martinez Luna Adad Marcel
		Urbina Gar�a Israel priori y posteriori
*/
#include<stdlib.h>
#include<stdio.h>
/**
Funci�n que obtiene el valor n de la secuencia de fibonacci de manera recursiva
*/
int fibonacci_rec(int cant)
{
	int contador=0;
	if(cant>1)
	{
		contador++;
		return fibonacci_rec(cant-1)+fibonacci_rec(cant-2);
	}
	else
	{
		contador++;
		return 1;
	}
}
/**
Funci�n que obtiene el valor n de la secuencia de fibonacci de manera ciclica
*/
void fibonacci_ciclo(int cant)
{
	int contador=0;
	int i,fib[cant];
	for(i=0;i<cant;i++)
	{
		contador++;
		if(i<2)
		{
			contador++;
			fib[i]=1;
		}
		else
		{
			contador++;
			fib[i]=fib[i-1]+fib[i-2];
		}
	}
	printf("%d \n",fib[cant-1]);
	printf("Cantidad de pasos: %d\n",contador);
}
void main()
{
	int n=10,i;
/*	printf("Implementaci�n ciclica\n");
	for(i=0;i<n;i++)	
	{
		printf("%d \n",fibonacci_rec(i));
	}*/
	printf("Implementaci�n ciclica\n");
	fibonacci_ciclo(n);
	printf("Implementaci�n recursiva\n");
	printf("%d",fibonacci_rec(n-1));
}
