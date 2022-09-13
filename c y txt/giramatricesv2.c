#include<stdio.h>
#include<stdlib.h>
/*
INstituto Politécnico Nacional
Escuela Superior de Cómputo
Martinez Luna Adad Marcel
Urbina García Alan Israel
*/

/**
*@brief variable global cuya acrácteristica es la de determinar el tamaño de las matrices en las funciones
*
*
*/
int n;
/**
*@brief Función auxiliar para la impresión de las matrices
*
*@param n
*@param mat
*@return 
*/
void imprimirmat(int mt[n][n],int m)
{
	int i,j,cont2=0;
	for(i=0;i<m;i++)
  	{
  		for(j=0;j<m;j++) 
  		{	cont2++;
		  	printf("%c",mt[i][j]);
		}
		putchar('\n');
	}
	printf("\ncontador imprimirmat: %d\n",cont2);
}


/**
*@brief Función que rota la imagen de manera recursiva, dividiendola en sus filas para que se manejen de manera similar a vectores
*
*@param girada
*@param mat
*@param m
*@return int
*/
int girarmatrec(int fila,int col,int mat[n][n],int temp[n][n],int cont3)
{
	while(fila!=n)
	{
		if(col!=n)
		{
			temp[fila][col]=mat[col][fila];cont3++;
			col+=1;cont3++;
			return girarmatrec(fila,col,mat,temp,cont3);
		}
		else
		{
			fila+=1;cont3++;
			return girarmatrec(fila,0,mat,temp,cont3);
			
		}
	}
	return cont3;
}

/**
*@brief Fnción auxiliar para la impresión de las matrices
*
*@param n
*@param mat
*@return 
*/
int girarmat(int mt[n][n])
{
	int i,j,cont=0;
	int girada[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cont++;
			girada[i][j]=mt[j][i];
		}
	}
	printf("contador girarmat: %d\n",cont);
	imprimirmat(girada,n);
}

/**
 * @brief Esta función cuenta las columnas en la imagen dentro del archivo, no toma en cuenta el salto de linea
 * 
 * @param img 
 * @return int 
 */
int contarcol(FILE *img)
{
    int col=0;
    printf("calculando dimensiones\n");
    while(!feof(img))
    {
      if (fgetc(img)!=10)
      {
          col++;
      }
      else
      {
          break;
      }    
    }
    return col;
}

/**
 * @brief Esta es para que no se vea tan lleno el main.
 * 
 * @param img 
 * @return  
 */
void principal(FILE *img)
{
	int i,j,filas,columnas,letra,cont=0;
   
    columnas=contarcol(img);
    
    n=columnas;
    
	printf("La matriz va a ser de %dx%d\n",columnas,columnas);
	
    fseek(img,0,SEEK_SET);//regresa la posición en el archivo a la posición de origen
    
    int mat[columnas][columnas],girada[columnas][columnas],girada2[columnas][columnas];
    
  	for(i=0;i<columnas;i++) //Es hasta el valor de columnas por que se incluyen saltos de linea o carácteres no imprimibles
  	{
  		for(j=0;j<=columnas;j++) //Es hasta el valor de columnas por que se incluyen saltos de linea o carácteres no imprimibles
  		{
  			letra=fgetc(img);
  			if(letra!='\n' && letra!=-1)
  			{	
  				mat[i][j]=letra;
			}	
		}
	}
	fclose(img);
	
	printf("imagen original\n");
	imprimirmat(mat,n);

    putchar('\n');
    
    printf("Rotacion no recursiva\n");
    girarmat(mat);
    
    putchar('\n');
    
   printf("Rotacion recursiva\n");
   printf("contador girarmatrec: %d\n",girarmatrec(0,0,mat,girada2,0));
   imprimirmat(girada2,n);
}

/**
*@brief Función principal del programa
*
*@param 
**@return
**/
void main()
{
    FILE *img;
    img=fopen("m16.txt","r+t");//las matrices tiene que ser perfectamente cuadradas o falla
    if(img)
    {
        principal(img);
    }
    else
    {
        printf("No se pudo cargar la imagen");
    }
}
