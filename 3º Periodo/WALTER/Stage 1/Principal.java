/*

POO - Prof. Walter Travassos
Raniel da Silva Evangelista - 1910026087

[PROJETO da 1º UNIDADE]
[Meia Pirâmide, Jogo da Velha e Manipulação de Arquivo .txt]


*/

class Principal {
    
    //Instancia a classe de Utilidade
    static Util u = new Util();
    
    //Projetos
    static MeiaPiramide meiaPiramide = new MeiaPiramide();
    static JogoDaVelha veia = new JogoDaVelha();
    static FileManager file = new FileManager();


    public static void main(String[] args) {
        //Inicia a aplicação
        ProjetoList();
    }

    
    public static void ProjetoList(){

        boolean sair = false;
        u.Escrever("Bem vindo aos projetos de\nProgramação Orientada à Objetos\n"+
        "Aluno: Raniel Evangelista - 1910026087\n");

        u.Escrever("O projeto '1 - Meia Piramide' pode ler um arquivo 'numeros.txt' que é\n"+
        "gerado pelo  projeto '3 - FileManager'. É ideal que entre em 'File Manager' primeiro, antes de entrar na 'Meia Piramide'.");

        do{
            //Entramos no loop das questões.            
            u.Escrever("\nEscolha um:\n"
            + "1 - Meia Pirâmide\n"
            + "2 - Jogo da Velha\n"
            + "3 - File Manager\n"
            + "0 para Sair");

            u.Escrever("OPCAO:");
            String entrada; //Entrada do usuário.
            entrada = u.Entrada(); //Pega a entrada do usuario
            
            switch(entrada){
                case "1": //Meia Piramide
                    meiaPiramide.Iniciar(u);
                    break;
    
                case "2": //Jogo da Velha
                    veia.Iniciar(u);
                    break;
    
                case "3": //File Manager (.txt)
                    file.Iniciar(u);
                    break;

                case "0": //SAIR
                    sair = true;
                    break;
            }
            
        } while (!sair); //Mantem o loop enquanto a opção não for "0"
    }
}
