
//Modelo ALUNO para os testes, com os seus Gets e Sets.
public class Aluno {
    private String nome;
    private Aluno anterior; 
    private Aluno proximo; 

    public String getNome(){ return nome; }
    public void setNome(String _nome){ nome = _nome; }
    public Aluno getAnterior(){ return anterior; }
    public void setAnterior(Aluno _anterior){ anterior = _anterior; }
    public Aluno getProximo(){ return proximo; }
    public void setProximo(Aluno _proximo){ proximo = _proximo; }
}