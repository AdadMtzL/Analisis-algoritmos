/*
Insituto Politecnico Nacional
Escuela Superior de Cómputo

Urbina Garcia ALan Israel
Martinez Luna Adad Marcel
*/
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(0));
	int m,n,r;
	int ct = 0;
	m=3;ct++;
	n=5;ct++;
	printf("Valores recibidos m=%d y n=%d\n",m,n);ct++;
	
	ct++;
	while(n!=0)
	{
		r=m%n;ct++;
		m=n;ct++;
		n=r;ct++;
	}
	printf("El minimo común divisor es %d \n",m);
	printf("El numero de pasos fue de: %d",ct);
	return 0;
}
