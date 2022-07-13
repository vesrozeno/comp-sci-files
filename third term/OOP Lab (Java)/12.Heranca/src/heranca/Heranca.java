/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package heranca;

/**
 *
 * @author joao-lucas.lima
 */
public class Heranca {

    
     
     
    public static void main(String[] args) {
        Pessoa jose = new Pessoa("José", 24,'M',1);
        Aluno maria = new Aluno("Maria",19,'F',0, 8.5,772);
        
        Professor aleardo = new Professor("Aleardo",16,'M',0,30000,2);
        Funcionario joaquin = new Funcionario("Joaquin",10,'M',0,100);
        
        
       
        
        
        
        jose.registrarFalta(1);
        maria.registrarFalta(0);
        
        System.out.println(aleardo.getNome());
        System.out.println(jose.getNome());
        System.out.println(maria.getNome());
        
        
    }
    
}
