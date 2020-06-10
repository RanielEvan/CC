
public class MeiaPiramide {

    //File Manager
    FileManager file = new FileManager();

    /*
    [MEIA PIRAMIDE]
    Aqui o usuario tem a opção de Digitar Numeros Manualmente
    ou ler o arquivo "numeros.txt" que é gerado pelo Projeto 3.
    */

    //Classe de utilidades...
    Util u;

    //Inicializa a MeiaPiramide
    public void Iniciar(Util _u){

        u = _u; //Util.
        
        u.Escrever("Bem vindo ao Meia Pirâmide!\n"+
        "Você deseja:\n"+
        "1 - DIGITAR NUMEROS?\n"+
        "2 - LER ARQUIVO \"numeros.txt\"?");
        
        u.Escrever("OPCAO:");
        String entrada = u.Entrada();
        
        switch(entrada){
            case "1":
                //Digita os numeros manualmente
                u.Escrever("Digite vários numeros separados por espaço.");
                u.Escrever("NUMEROS:");
                entrada = u.Entrada(); //Entrada do usuario
                break;
            case "2":
                //Ler arquivo de Texto com os numeros
                entrada = file.LerTexto("numeros.txt");
                break;
        }
        
        QuebrarString(entrada);
    }

    //Quebra a string e mostra o resultado
    private void QuebrarString(String numeros){

        String[] numStr = numeros.split(" ");

        int tamanhoLinha = 1; //Tamanho inicial
        int indiceNaLinha = 0; //Posicao atual na linha

        String meiaPiramide = ""; //A meia piramide construida

        int menorNumero = 0; //Armazena o menor Numero

        int somaMenores = 0; //O resultado da soma
        String somaMenoresStr = ""; //String dos menores numeros para mostrar a soma

        //
        for(int i=0; i < numStr.length; i++){
            
            int numInt = Integer.parseInt(numStr[i]); //Transforma esse numero em INT

            meiaPiramide += "[" + numStr[i] + "] "; //inclui na String da Meia Piramide
            
            if(indiceNaLinha == 0) //Se for a PRIMEIRA posicao da linha
                menorNumero = numInt;  //Atribuimos este numero como Menor.

            if (numInt < menorNumero){
                menorNumero = numInt;
            }

            indiceNaLinha++; //Incrementa no indice da linha

            //Verifica se já chegou no limite da linha
            if(indiceNaLinha == tamanhoLinha){

                somaMenores += menorNumero; //Soma o menor numero dessa linha.
                somaMenoresStr += menorNumero; //Coloca numero na string da soma que mostra no final

                somaMenoresStr += (i == numStr.length - 1)?" = ": " + "; 

                tamanhoLinha++;
                indiceNaLinha = 0;

                meiaPiramide += "\n"; //Pula linha
            }
        }

        u.Escrever(meiaPiramide);
        u.Escrever("SOMA DOS MENORES: " + somaMenoresStr + somaMenores);
        u.Escrever("---------------------");

    }
}