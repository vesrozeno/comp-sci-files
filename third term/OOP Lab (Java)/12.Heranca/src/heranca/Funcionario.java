package heranca;

/**
 *
 * @author joao-lucas.lima
 */
public class Funcionario extends Pessoa {
    private double salario;
    

    public Funcionario(String nome, int idade, char sexo, int faltas, double salario) {
        super(nome, idade, sexo, faltas);
        this.salario = salario;
    }
    
    public void aumentarSalario(double salario){
        this.salario = salario;
    }
    
    
    
    
}
