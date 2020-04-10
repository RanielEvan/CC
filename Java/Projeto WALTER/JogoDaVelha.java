
public class JogoDaVelha {

    //Utilidade..
    Util u;
    int[][] valores; //Matriz de valores.

    public void Iniciar(Util _u){
        
        u = _u; //UTIL
        boolean sair = false; //Controla o loop de jogadas

        valores = new int[3][3]; //Zera a matriz
        int jogadorAtual = -1; //Jogador atual (pode ser 'Jogador -1' e 'Jogador 1')
        char jogadorIndicador = 'A'; //Jogador A ou B

        u.Escrever("Bem vindo ao Jogo da Véia!\n"+
        "Aqui irás batalhar contra ti mesmo, estou torcendo por você!\n");
        u.Escrever("Para sair digite \"SAIR\"\nPara fazer a jogada, digite 'LINHA COLUNA'. Ex.: 3 2");

        u.Escrever(DesenharJogo()); //Desenha o tabuleiro vazio

        do{
            
            u.Escrever("JOGADOR "+jogadorIndicador+"\nJOGADA:");
            String jogada = u.Entrada();

            //Checa se foi comando de 'sair'
            if(jogada.equalsIgnoreCase("sair")) {
                sair = true;

            } else {
                //Tenta fazer a jogada com o valores que jogador digitou
                if(FazerJogada(jogada, jogadorAtual)){
                    //Muda de jogador apos a jogada.
                    jogadorAtual = (jogadorAtual == 1)? -1 : 1; 
                    jogadorIndicador = (jogadorIndicador == 'A')?'B':'A';
                }

                u.Escrever(DesenharJogo()); //Desenha o tabuleiro apos a jogada

                //Verifica se apos a jogada, alguem ganhou
                if(ChecarVencedor()){
                    sair = true; //Se alguem ganhou, podemos sair do jogo.
                }
            }

        } while (!sair);

    }

    //Metodo que desenha o Jogo Da Velha
    private String DesenharJogo(){

        String saida = "";
        for(int c=0; c<3;c++){ //COLUNAS
            for(int l=0; l<3; l++){ //LINHAS

                //Se houver valores nesses campos, desenha o Simbolo do jogador.
                if(valores[c][l] == 1)
                    saida += "X"; //Jogador 1
                else if (valores[c][l] == -1)
                    saida += "O"; //Jogador 2
                else
                    saida += (c==2)?" ":"_"; //Campo vazio.
                
                if(l==2) //Ao chegar no fim da linha
                    saida += "\n"; //Quebra linha
                else
                    saida += "|"; //Desenha pipe
            }
        }

        return saida;
    }

    //Faz a jogada passando a jogada e o jogador como parametro
    private boolean FazerJogada(String jogada, int jogador){

        try {
            //pega o texto digitado pelo player e divide (pelo espaço entre eles)
            String[] numStr = jogada.split(" ");
            
            //Converte os textos em numero
            int col = Integer.parseInt(numStr[0]) - 1;
            int row = Integer.parseInt(numStr[1]) - 1;

            if(valores[col][row] == 0){ //Se nessa posicao estiver 0 
                valores[col][row] = jogador; //Salva o simbolo do jogador nessa posicão
                return true; //Retorna verdadeiro, indica que a jogada deu certo.
            } else {
                //Caso o valor dessa posicao seja diferente de 0
                //Indica que alguem ja jogou aqui, logo a jogada dará errado!
                u.Escrever("~ Essa posição já foi marcada!");
                return false;
            }

        } catch(Exception e){

            //Entra aqui caso o valor tenha sido invalido e a jogada tenha dado errado
            u.Escrever("~ Não foi possivel fazer a jogada!");
            u.Escrever("~ Para fazer a jogada, digite 'COLUNA LINHA'\nEx.: 2 1 ou 3 3");
            
            return false;
        }
    }

    //Verifica se alguem ganhou...
    private boolean ChecarVencedor() {

        //Faz a checagem por partes.
        int vencedor = ChecarLinhas();
        
        if(vencedor == 0)
            vencedor = ChecarColunas();

        if(vencedor == 0)
            vencedor = ChecarDiagonais();


        //Se alguem ganhou, mostra mensagem e retorna verdadeiro.
        if(vencedor == -1){
            u.Escrever("~ Vencedor foi JOGADOR A!\nParabéns sempre acreditei em você!");
            return true;
        } else if(vencedor == 1) {
            u.Escrever("~ Vencedor foi JOGADOR B!\nVocê é demais!");
            return true;
        }

        //Se ninguem ganhou, retorna falso e continua o jogo.
        return false;
    }

    //Checa as linhas
    private int ChecarLinhas(){
        for(int l=0; l<3; l++){
            //Soma os valores de cada linha
            int soma = valores[l][0] + valores[l][1] + valores[l][2];
            if(soma == -3){
                return -1;
            } else if (soma == 3){
                return 1;
            }
        }
        return 0;
    }

    //Checa as linhas
    private int ChecarColunas(){
        for(int c=0; c<3; c++){
            //Soma os valores de cada coluna
            int soma = valores[0][c] + valores[1][c] + valores[2][c];
            if(soma == -3){
                return -1;
            } else if (soma == 3){
                return 1;
            }
        }
        return 0;
    }

    //Checa as linhas
    private int ChecarDiagonais(){
        //Checa Diagonais
        int soma = valores[0][0] + valores[1][1] + valores[2][2];
        if(soma == -3){
            return -1;
        } else if (soma == 3){
            return 1;
        }

        soma = valores[0][2] + valores[1][1] + valores[2][0];
        if(soma == -3){
            return -1;
        } else if (soma == 3){
            return 1;
        }
        return 0;
    }
}