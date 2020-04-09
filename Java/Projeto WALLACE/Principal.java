/*

ESTRUTURA DE DADOS - Prof. Walace Sartori
Raniel da Silva Evangelista - 1910026087

[PROJETO da 1º UNIDADE]
[Listas e Pilhas, Sequenciais e Encadeadas]
• Existe uma classe para cada tipo de Lista/Pilha com suas implementações;
• Estou usando o Modelo de ALUNO que foi visto nas aulas;
• O codigo está todo comentado para melhor entendimento;
• Criei uma classe com funcoes que utilizo muito, como Escrever() e Esperar();

*/

import java.util.Scanner;

class Principal {
    
    //Instancia a classe de Utilidade
    static Util u = new Util();
    
    //Intanciamos o Scanner
    static Scanner sc = new Scanner(System.in);

    //Classes das Listas/Pilhas
    static ListaSequencial lista1 = new ListaSequencial();
    static ListaEncadeada lista2 = new ListaEncadeada();
    static PilhaSequencial lista3 = new PilhaSequencial();
    static PilhaEncadeada lista4 = new PilhaEncadeada();

    public static void main(String[] args) {
        //Inicia a aplicação
        ListasApp();
    }

    
    public static void ListasApp(){

        boolean sair = false;
        u.Escrever("Bem vindo ao app sobre Listas e Pilhas\n");
        
        do{
            
            //Entramos no loop das questões.            
            u.Escrever("\nDigite a OPCAO que deseja:\n"
            + "1 - Lista Sequencial\n"
            + "2 - Lista Encadeada\n"
            + "3 - Pilha Sequencial\n"
            + "4 - Pilha Encadeada\n"
            + "0 para Sair\n");
            
            u.Escrever("OPCAO:");
            String entrada; //Entrada do usuário.
            entrada = sc.nextLine(); //Pega a entrada do usuario
            
            switch(entrada){
                case "1": //Lista Sequencial
                    lista1.Iniciar(sc);
                    break;
    
                case "2": //Lista Encadeada
                    lista2.Iniciar(sc);
                    break;
    
                case "3": //Pilha Sequencial
                    lista3.Iniciar(sc);
                    break;
    
                case "4": //Pilha Encadeada
                    lista4.Iniciar(sc);
                    break;

                case "0": //SAIR
                    sair = true;
                    break;
            }
            
        } while (!sair); //Mantem o loop enquanto a opção não for "0"
    }
}
