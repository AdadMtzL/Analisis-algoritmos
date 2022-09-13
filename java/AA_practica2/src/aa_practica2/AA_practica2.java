package aa_practica2;
import java.util.Scanner;

/**
 * Urbina Garcia Alan Israel
 * Martinez Luna Adad Marcel
 */
public class AA_practica2 {
    public static void main(String[] args) {
        Scanner a = new Scanner(System.in);
        AA_practica2 llamar = new AA_practica2();
        
        System.out.print("Cuantos numeros perfectos quieres que encuentre?: ");
        int numFound = a.nextInt();
        llamar.BuscarPerfecto(numFound);
    }

    public int Perfecto(int numero){  //funcion Perfecto()
        int division, suma=0;
        int incre = 0;
        int[] vec = new int[numero];

        for (int i = 1; i < numero; i++) {
            division = numero % i; //comprueba si es divisible
            if (division == 0) {    //si es divisible lo va a guardar
                vec[incre] = i; //guarda los valores en un arreglo
                incre++;        //recorre el arreglo
            } 
        }       
        for (int i = 0; i < numero; i++) {
            suma = suma + vec[i];       //suma los elementos del arreglo
        }
        int siono;                      //esta variable nos ayudara a contar en el metodo BuscarPerfecto
        if (suma == numero){ 
            System.out.println("EL numero: "+numero+" es un numero perfecto");
            siono = 1;
        }else{
            //System.out.println("Lo siento "+numero+" No es un numero perfecto");
            siono = 0;
        }
        return siono;
    }
    
    public void BuscarPerfecto(int num){
        
        AA_practica2 llamarFunc = new AA_practica2();
        int numeroFound = num;
        
        int stop = 1, incre = 6; 
        
        while (stop <= numeroFound){
            int resultado = llamarFunc.Perfecto(incre);
            if (resultado == 1){
                stop++;
            }
            incre++;
        }
    }
}
