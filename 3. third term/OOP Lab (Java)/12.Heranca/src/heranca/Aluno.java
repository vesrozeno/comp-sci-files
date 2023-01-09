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
public class Aluno extends Pessoa {
    private double media;
    private int ra;
    
    public Aluno(String nome, int idade, char sexo, int faltas, double media,int ra){
        super(nome,idade,sexo,faltas);
        this.media = media;
        this.ra = ra;
    
    }
    
    public void alterarMedia(double media){
        this.media = media;
    }
    
    public void alterarRA(int ra){
        this.ra = ra;
    }
    
    
}
