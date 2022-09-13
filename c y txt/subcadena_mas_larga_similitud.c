/**
* Instituto Politécnico Nacional
* Escuela Superior de Cómputo
* 
* Martinez Luna Adad Marcel
* Urbina García Alan Israel
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
*@brief Determinara cual es el valor mas alto de dos enteros.
*
*@param v1
*@param v2
*@return int
*/
int Maximo(int v1,int v2)
{
	if(v1>v2)
	{
		return v1;
	}
	else
	{
		if(v1==v2)
		{
			return v1;
		}
		else
		{
			return v2;
		}
	}
}

/**
*@brief llena una matriz de tal manera que esta tiene dimensiones nxm y determina mediante el algoritmo de la subcadena su longitud
*
*@param mat_din
*@param arch1
*@param arch2
*@param longitud1
*@param longitud2
*@return char*
*/
int dinamico(char *arch1,char *arch2,int longitud1,int longitud2)
{
	int mat_din[longitud1][longitud2];
	int i,j,temp=0;
	for(i=0;i<longitud1;i++)
	{
		for(j=0;j<longitud2;j++)
		{
			mat_din[i][j]=0;
		}
	}
	
	for(i=0;i<longitud1;i++)
	{
		for(j=0;j<longitud2;j++)
		{
			if(arch1[i]==arch2[j])
			{
				if(i==0 && j>0)
				{
					mat_din[i][j]=mat_din[0][j-1]+1;
				}
				else
				{
					if(i>0 && j==0)
					{
						mat_din[i][j]=mat_din[i-1][0]+1;
					}
					else
					{
						if(i==0 && j==0)
						{
							mat_din[i][j]=mat_din[0][0]+1;
						}
						else
						{
							mat_din[i][j]=mat_din[i-1][j-1]+1;
						}
					}
				}
			}
			else
			{
				if(i==0 && j>0)
				{
					mat_din[i][j]=Maximo(mat_din[0][j],mat_din[0][j-1]);
				}
				else
				{
					if(i>0 && j==0)
					{
						mat_din[i][j]=Maximo(mat_din[i-1][0],mat_din[i][0]);
					}
					else
					{
						if(i==0 && j==0)
						{
							mat_din[i][j]=0;
						}
						else
						{
							mat_din[i][j]=Maximo(mat_din[i-1][j],mat_din[i][j-1]);
						}
					}
				}
				
			}
		}
	}
	
	for(i=0;i<longitud1;i++)
	{
		for(j=0;j<longitud2;j++)
		{
			if(temp<mat_din[i][j])
			{
				temp=mat_din[i][j];
			}
		}
	}
	return temp;
}

/**
*@brief llena los arreglos char con las letras del archivo que no sean espacios o saltos de linea
*
*@param archivo
*@param contenedor
*@return char*
*/
void LlenarArreglo(FILE *archivo,char *contenedor, int longitud)
{
	char letra;
	int ind=0;
	while(!feof(archivo) && ind<longitud)
	{
		letra=fgetc(archivo);
		if(letra==32 || letra==10)
		{
			//No va a hacer nada
		}
		else
		{
			contenedor[ind]=letra;
			ind++;
		}
	}
}

/**
*@brief cuenta los carácteres que no son saltos de linea y espacios
*
*@param archivo
*@return int
*/
int Contar_Letras(FILE *archivo)
{
	int lt=0;
	int letra;
	while(!feof(archivo))
	{
		letra=fgetc(archivo);
		if(letra==32 || letra==10)
		{
			//No va a hacer nada
		}
		else
		{
			lt+=1;
		}
	}
	return lt-1;
}

/**
*@brief Determina el porcentaje de similitud con base a la subcadena más larga y la longitud del documento original sin espacios o saltos de linea
*
*@param maxsubcad
*@param longitud
*@return float
*/
float Similitud(int maxsubcad,int longitud)
{
	float temp,temp1;
	temp=(float)maxsubcad;
	temp1=(float)longitud;
	return ((float)((temp/temp1)*100));
}

/**
*@brief función principal del programa
*
*@param 
*@return 
*/
void main()
{
	FILE *f1,*f2;
	char *nombrearchivo=malloc(sizeof((char)100)),letra;
	int longitud1,longitud2,i,maxsubcad;
	do
	{
		printf("Indique el nombre del archivo original en la misma carpeta que el ejecutable\n");
		gets(nombrearchivo);
		f1=fopen(nombrearchivo,"r");
		system("cls");
	}while(!f1);
	do
	{
		printf("Indique el nombre del archivo a comparar en la misma carpeta que el ejecutable\n");
		gets(nombrearchivo);
		f2=fopen(nombrearchivo,"r");
		system("cls");
	}while(!f2);
	
	longitud1=Contar_Letras(f1);
	printf("longitud1: %d\n",longitud1);
	
	longitud2=Contar_Letras(f2);
	printf("longitud2: %d\n",longitud2);
	
	char arch1[longitud1],arch2[longitud2];
	
	fseek(f1,0,SEEK_SET);
	fseek(f2,0,SEEK_SET);
	
	LlenarArreglo(f1,arch1,longitud1);
	LlenarArreglo(f2,arch2,longitud2);
	
	fclose(f1);
	fclose(f2);
	
	maxsubcad=dinamico(arch1,arch2,longitud1,longitud2);
	printf("La maxima subcadena es de %d\n",maxsubcad);
	
	printf("La similitud es del %f por ciento",Similitud(maxsubcad,longitud1));
	
}
