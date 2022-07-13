
package heranca;

/**
 *
 * @author joao-lucas.lima
 */
public class Professor extends Pessoa {
    private double salario;
    private int horassemanais;

    public Professor(String nome, int idade, char sexo, int faltas,double salario,int horassemanais) {
        super(nome, idade, sexo, faltas);
        this.salario = salario;
        this.horassemanais = horassemanais;
    }
    
    public void alterarHorasSemanais(int horassemanais) {
        this.horassemanais = horassemanais;
    }


    
    public void aumentarSalario(double salario){
        this.salario = salario;
    }
}
