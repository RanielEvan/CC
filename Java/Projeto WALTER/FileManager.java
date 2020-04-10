import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

//Essa é a classe para manipulação de Arquivos .TXT
public class FileManager {
    
    //Classe de utilidadex
    Util u;

    //Inicia
    public void Iniciar(Util _u){

        u = _u; //Util

        u.Escrever("Bem vindo ao FileManager!\n"+
        "Aqui irás manipular o arquivo \"numeros.txt\", que é o arquivo usado na 'MeiaPiramide'");
        
        boolean sair = false;

        do{
            u.Escrever("\nOpções:\n"+
            "1 - ESCREVER NOVO TEXTO\n"+
            "2 - LER TEXTO DO ARQUIVO\n"+
            "3 - APAGAR TEXTO DO ARQUIVO\n"+
            "0 - VOLTAR");
            
            u.Escrever("OPCAO:");
            String entrada = u.Entrada();
    
            switch(entrada){
                case "1": //Escrever novo conteudo
                    u.Escrever("Digite o novo texto do arquivo.");
                    u.Escrever("NOVO TEXTO:");
                    entrada = u.Entrada();
                    SalvarTexto(entrada, "numeros.txt");
                    break;
    
                case "2": //Ler Arquivo
                    u.Escrever("TEXTO DO ARQUIVO: ");
                    u.Escrever("\"" +LerTexto("numeros.txt") + "\"");
                    break;
                
                case "3": //Apagar conteudo do Arquivo
                    SalvarTexto("", "numeros.txt");
                    break;

                case "0":
                    sair = true;
                    break;
            }

        } while (!sair);

    }


    //Metodo que salva o texto em arquivo...
    public void SalvarTexto(String texto, String nomeArquivo) {
            
        try{
            //Para o FileWriter escrever no mesmo diretorio do Aplicativo
            //É necessário Compilar ele manualmente na pasta (javac Principal.java) depois rodar (java Principal)
            //Se testar pelo VisualCode(eu) ele gera o arquivo na build que fica em outra pasta.
            FileWriter arq = new FileWriter(nomeArquivo);
            arq.write(texto);
    
            arq.close();

            if(texto != "")
                u.Escrever("~ Texto salvo no arquivo \"numeros.txt\"");
            else
                u.Escrever("~ Conteudo do arquivo \"numeros.txt\" apagado!");
                

        } catch(Exception e){
            u.Escrever("~ Erro ao salvar arquivo!");
        }
    }


    //Metodo para ler arquivos de texto 
    public String LerTexto(String nomeArquivo){

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
            u.Escrever("~ Falha ao ler texto do arquivo \""+nomeArquivo+"\"");
            return "";
        }

       
    }

}