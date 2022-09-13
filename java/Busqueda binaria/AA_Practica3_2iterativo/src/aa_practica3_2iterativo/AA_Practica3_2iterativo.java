/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aa_practica3_2iterativo;

import java.util.Scanner;

/**
 *
 * @author AlanU
 */
public class AA_Practica3_2iterativo {


    public static int cont;
    static int BusquedaTernaria(int index, int longitud, int num, int array[])
     {
        while (longitud >= index) {
            int mid1 = index + (longitud - index) / 3;
            int mid2 = longitud - (longitud - index) / 3;
            if (array[mid1] == num) {
                return mid1;
            }

            if (array[mid2] == num) {
                return mid2;
            }
 
            if (num < array[mid1]) {
                longitud = mid1 - 1;
            }

            else if (num > array[mid2]) {
                index = mid2 + 1;
            }

            else {
                index = mid1 + 1;
                longitud = mid2 - 1;
            }
        }
        return -1;
    }
    
    public static void main(String[] args) {
        int index, longitud, p, num;
        Scanner a = new Scanner(System.in);
        int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        index = 0;
        longitud = 9;
        for(int i = 0; i<=30 ;i++){
            cont =0;
            //System.out.print("Que numero deseas encontrar: ");
            num = i;//a.nextInt();
            p = BusquedaTernaria(index, longitud, num, array);
            if (p == -1) {
                cont++;
                //System.out.println("El numero "+num+" NO fue encontrado");
                System.out.println("numero: "+num+ "\tpasos: "+cont);
            } else {
                cont++;
                //System.out.println("El numero " + num + " esta en la posicion " + p+" del arreglo");
                System.out.println("numero: "+num+ "\tpasos: "+cont);
            }
        }
    }
}
