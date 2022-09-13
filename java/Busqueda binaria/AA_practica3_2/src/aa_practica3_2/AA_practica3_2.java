/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aa_practica3_2;



import java.util.Scanner;

/**
 *
 * @author AlanU
 */
public class AA_practica3_2 {


    static int BusquedaTernaria(int index, int longitud, int num, int array[])
    {
        int cont=0;
        if (longitud >= index) {
            
            int mid1 = index + ((longitud - index) / 3);
            int mid2 = longitud - ((longitud - index) / 3);
                  
            
            if (array[mid1] == num) {
                return mid1;
            }
               
            if (array[mid2] == num) {
                return mid2;
            }
                        
            if (num < array[mid1]) {
                return BusquedaTernaria(index, mid1 - 1, num, array);
            }
            else if (num > array[mid2]) {
                return BusquedaTernaria(mid2 + 1, longitud, num, array);
            }
            else {
                return BusquedaTernaria(mid1 + 1, mid2 - 1, num, array);
            }
        }
        return -1;
    }

    public static void main(String[] args) {     
        int index, longitud, p, num;
        Scanner a = new Scanner(System.in);
        int[] array = {1, 2, 3,  4, 5, 6,  7, 8, 9};
        
        // Incio del arreglo
        index = 0;
        // Longitud del arreglo
        longitud = 8;
        
        int mid1 = index + ((longitud - index) / 3);
        int mid2 = longitud - ((longitud - index) / 3);
        
        System.out.print("Que numero quieres buscar?: ");
        num = a.nextInt();
        
        p = BusquedaTernaria(index, longitud, num, array); 
        if (p == -1) {
        System.out.println("El numero "+num+" NO fue encontrado");
        } else {
            if (array[mid1] == num) {
                System.out.print("El numero esta en el indice 1");
            }
            if(array[mid2] == num){
                System.out.print("El numero esta en el indice 1");
            }
            System.out.println("\nEl numero " + num + " esta en la posicion " + p+" del arreglo");
        }   
    }
}
