import java.util.concurrent.TimeUnit;

//Classes com algumas utilidades, para evitar digitar demais...
public class Util {

    public void Escrever(String texto) {
        if (texto.endsWith(":"))
            System.out.print(texto);
        else
            System.out.println(texto);
    }

    public void Esperar() {
        try {
            TimeUnit.MILLISECONDS.sleep(800);
        } catch (InterruptedException e) {
            Escrever("Houve um erro!");
        }
    }
}