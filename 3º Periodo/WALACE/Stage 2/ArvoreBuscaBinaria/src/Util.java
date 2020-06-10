import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class Util {
    //Metodo para ler arquivos de texto (nomeArquivo.txt)
    public String LerArquivo(String nomeArquivo){

        try {
            //Classes de leitura
            FileReader fr = new FileReader(nomeArquivo);
            BufferedReader br = new BufferedReader(fr);
            
            String retorno = ""; //Retorno do texto lido, inicia vazia.
            
            while (br.ready()) {
                retorno += br.readLine(); //lê a proxima linha e incrementa a String
            }

            //Fecha os leitores...
            br.close(); 
            fr.close();

            return retorno;

        } catch (Exception e) {
            System.out.println(e + "~ Falha ao ler arquivo \""+nomeArquivo+"\"");
            return "";
        }

    }
}
