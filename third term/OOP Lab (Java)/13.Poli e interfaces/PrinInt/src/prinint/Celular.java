/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prinint;

/**
 *
 * @author vesrozeno
 */
public class Celular implements Aparelho, Movel {
    
    private double preco;
    private String nome;
    private double credito;

    public Celular(double preco, String nome, double credito) {
        this.preco = preco;
        this.nome = nome;
        this.credito = credito;
    }

    
    
    public double getPreco() {
        return this.preco;
    }

    public String getNome() {
        return this.nome;
    }

    public double getCredito() {
        return this.credito;
    }
    
    
    
    
}
