
public class NoArvore {
	int			valor;
	NoArvore	direita;
	NoArvore	esquerda;

	public NoArvore busca(NoArvore no, int valorprocurado) {
		if(no == null)
			return null;
		
		if(no.valor > valorprocurado)
			return busca(no.esquerda, valorprocurado);
		else if(no.valor < valorprocurado)
			return busca(no.direita, valorprocurado);
		else
			return no;
	}
	
	public NoArvore insere(NoArvore no, int novovalor) {
		if(no == null) {
			no = new NoArvore();
			no.valor = novovalor;
			no.esquerda = no.direita = null;
		}
		else if(novovalor < no.valor)
			no.esquerda = insere(no.esquerda, novovalor);
		else if(novovalor > no.valor)
			no.direita = insere(no.direita, novovalor);
	
		return no;
	}

	public void imprime(NoArvore raiz) {
		if (raiz != null) {
			// System.out.println(raiz.valor); // PRE ORDEM
			imprime(raiz.esquerda);
			// System.out.println(raiz.valor); // IN ORDEM
			imprime(raiz.direita);
			System.out.println(raiz.valor); // POS ORDEM
		}
	}
	
	public NoArvore removerPeloAntecessor(NoArvore raiz, int valoraremover) {
		// faz a busca pelo valor a ser removido
		if (raiz == null)
			return null;
		else if (raiz.valor < valoraremover) // 1
			raiz.direita = removerPeloAntecessor(raiz.direita, valoraremover);
		else if (raiz.valor > valoraremover) //2
			raiz.esquerda = removerPeloAntecessor(raiz.esquerda, valoraremover);
		else {	// passar por aqui significa que achou o nó com o
				// valor a remover.
				// agora vai remove-lo
				// segundo as 4 situações a seguir:

			// Não ter filhos (esquerda e direita == null) [FOLHA]
			if (raiz.esquerda == null && raiz.direita == null) {
				raiz = null;
			}
			// Ter filho apenas à direita (esquerda == null)
			else if (raiz.esquerda == null) {
				raiz = raiz.direita;
			}
			// Ter filho apenas à esquerda (direita == null)
			else if (raiz.direita == null) {
				raiz = raiz.esquerda;
			}
			
			// Ter dois filhos (esquerda e direita != null)
			else {
				NoArvore sub_esquerda = raiz.esquerda;
				// encontrar o nó com maior valor na subárvore
				while (sub_esquerda.direita != null) {
					sub_esquerda = sub_esquerda.direita;
				}
				// aqui a sub_esquerda.valor tem o maior valor
				raiz.valor = sub_esquerda.valor;
				sub_esquerda.valor = valoraremover;
				raiz.esquerda = removerPeloAntecessor(raiz.esquerda, valoraremover);
			}
		}
		return raiz;		
	}

	public NoArvore removerPeloSucessor(NoArvore raiz, int valoraremover) {
		// faz a busca pelo valor a ser removido
		if (raiz == null)
			return null;
			else if (raiz.valor > valoraremover) // 1
				raiz.esquerda = removerPeloSucessor(raiz.esquerda, valoraremover);
		else if (raiz.valor < valoraremover) // 2
			raiz.direita = removerPeloSucessor(raiz.direita, valoraremover);
		else {
			// Verificamos se existe valor maior, na sub arvore esquerda
			if (raiz.direita == null && raiz.esquerda == null) {
				raiz = null;
			}

			// Ter filho apenas a direita (esquerda == null) 
			else if (raiz.esquerda == null) {
				raiz = raiz.direita;
			}
			// Ter filho apenas a esquerda (direita == null)
			else if (raiz.direita == null) {
				raiz = raiz.esquerda;
			}
			// Ter dois filhos (esquerda e direita != null)
			else {
				NoArvore sub_direita = raiz.direita;
				// encontrar o nó com menor valor na subarvore Direita
				while (sub_direita.esquerda != null) {
					sub_direita = sub_direita.esquerda;
				}
				// aqui a sub_direita.valor tem o menor valor
				raiz.valor = sub_direita.valor;
				sub_direita.valor = valoraremover;
				raiz.direita = removerPeloSucessor(raiz.direita, valoraremover);
			}
		}
		return raiz;		
	}
}



