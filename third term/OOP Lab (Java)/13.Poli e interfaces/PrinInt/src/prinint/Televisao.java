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
public class Televisao implements Aparelho {
    
    private double preco;
    private double imposto;
    private String nome;
    private String descricao;

    public Televisao(double preco, String nome) {
        this.preco = preco;
        this.nome = nome;
    }


    public double getPreco() {
        return this.preco;
    }
    public double getImposto() {
        return imposto;
    }
    public String getNome() {
        return this.nome;
    }
    public String getDescricao() {
        return descricao;
    }
    
    public void setPreco(double preco) {
        this.preco = preco;
    }
    public void setImposto(double imposto) {
        this.imposto = imposto;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }
    
    
    
}
