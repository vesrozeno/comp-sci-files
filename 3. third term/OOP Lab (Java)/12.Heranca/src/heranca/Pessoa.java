package heranca;

public class Pessoa {
    protected String nome;
    protected int idade;
    protected char sexo;
    protected int faltas;                                    

    public Pessoa(String nome, int idade, char sexo, int faltas) {
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
        this.faltas = faltas;
    }

    public String getNome() {
        return nome;
    }
    
    public void registrarFalta(int falta){
        this.faltas = falta;
    }
    
    public void alterarIdade(int idade){
        this.idade = idade;
    }
    
    
    
    
    
}
