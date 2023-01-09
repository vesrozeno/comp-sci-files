import java.lang.Comparable;


public class Pessoa implements Comparable<Pessoa>{

    private String nome;
    private int idade;
    private double salario;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    @Override
    public int compareTo(Pessoa outraPessoa)
    {
        if(this.idade<outraPessoa.idade)
            return -1;
        else if(this.idade>outraPessoa.idade)
            return 1;
        else
            return 0;

    }
    
    public Pessoa(String nome, int idade, double salario)
    {
        this.nome = nome;
        this.idade = idade;
        this.salario = salario;
    }

    
    
}
