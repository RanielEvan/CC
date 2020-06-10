import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		
		NoArvore abb = new NoArvore();
		Scanner sc = new Scanner(System.in);
		Util util = new Util(); // Classe de utilidades.

		// Fazemos a leitura do "arquivo.txt"
		String arquivo = util.LerArquivo("numeros.txt");
		String[] numeros = arquivo.split(" "); // Separamos cada numero pelo espaço, fica um array de numeros.

		for(int i=0; i<numeros.length; i++) {
			abb.insere(abb, Integer.parseInt(numeros[i])); // inserimos numero na arvore...
			System.out.println("NUMERO INCLUIDO: " + numeros[i]);
		}
			
		System.out.println("Informe um numero para BUSCAR na lista de Numeros: ");
		int valor = sc.nextInt();

		// Recupera o valor passado pelo usuario
		NoArvore resultado = abb.busca(abb, valor);
		
		if(resultado == null)
		 	// Não encontrou o valor informado.
			System.out.println("Não encontrei o nº" + valor);
		else
			System.out.println("Encontrei o nº: " + resultado.valor);
		
		abb.imprime(abb);

		// Agora remove pelo ANTECESSOR
		System.out.println("Informe um numero para REMOVER (pelo antecessor) da lista de Numeros: ");
		abb.removerPeloAntecessor(abb, sc.nextInt()); // Remove o numero informado
		abb.imprime(abb);

		// Agora remove pelo SUCESSOR
		System.out.println("Informe um numero para REMOVER (pelo sucessor) da lista de Numeros: ");
		System.out.println("Informe um numero para REMOVER (pelo sucessor) da lista de Numeros: ");
		abb.removerPeloSucessor(abb, sc.nextInt()); // Remove o numero informado
		abb.imprime(abb);

		sc.close();
	}

}
