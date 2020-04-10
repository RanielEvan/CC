import java.util.Scanner;

//Classes com algumas utilidades, para evitar digitar demais...
public class Util {

    Scanner sc = new Scanner(System.in);
    
    //Escreve texto no console.
    public void Escrever(String texto) {
        if (texto.endsWith(":"))
            System.out.print(texto);
        else
            System.out.println(texto);
    }

    //Pega entrada do usuario
    public String Entrada(){
        return sc.nextLine();
    }

}