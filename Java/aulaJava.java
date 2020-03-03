import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		//Q1(sc);
		Q2(sc);
		
	}
	
	public static void Q1(Scanner sc) {
		
		
		Escrever("Informe seu nome:");
		String nome = sc.nextLine();
		
		Escrever("Informe o valor da hora trabalhada:");
		double valorHr = Double.parseDouble(sc.nextLine());
		
		Escrever("Quantas horas trabalhou nesse mês:");
		int horas = Integer.parseInt(sc.nextLine());
		
		
		Escrever("Funcionario: "+ nome);
		Escrever("Valor da hora: R$ "+ valorHr +" | Horas trabalhadas: "+ horas);
		Escrever("Total a receber R$ "+ valorHr * horas);
		
	}
	
	
	public static void Q2(Scanner sc) {
		
		Escrever("Qual valor do produto? ");
		double valor = Double.parseDouble(sc.nextLine());
		
		Escrever("Quanto o cliente pagou? ");
		double clientePagou = Double.parseDouble(sc.nextLine());
		
		Escrever("Preço do produto R$ "+ valor +" | Valor recebido R$ "+ clientePagou);
		Escrever("Troco para o cliente R$ "+ ((valor < clientePagou)? 0 : valor - clientePagou));
				
	}
	
	public static void Q2(Scanner sc) {
		
		Escrever("Qual valor do produto? ");
		double valor = Double.parseDouble(sc.nextLine());
		
		Escrever("Quanto o cliente pagou? ");
		double clientePagou = Double.parseDouble(sc.nextLine());
		
		Escrever("Preço do produto R$ "+ valor +" | Valor recebido R$ "+ clientePagou);
		Escrever("Troco para o cliente R$ "+ ((valor < clientePagou)? 0 : valor - clientePagou));
				
	}
	
	//Escreve textos...
	public static void Escrever(String texto) {
		System.out.println(texto);
	}
	
}
