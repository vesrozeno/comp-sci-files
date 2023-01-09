/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poli;

/**
 *
 * @author vesrozeno
 */
public abstract class Veiculo {
    
    private int ano;
    private int quantPneus;
    private String modelo;
    private String placa;
    
    public Veiculo(int ano, int quantPneus, String modelo, String placa)
    {
        this.ano = ano;
        this.quantPneus = quantPneus;
        this.modelo = modelo;
        this.placa = placa;
    }
    
    public int getAno() {
        return this.ano;
    }
    public int getQuantPneus() {
        return this.quantPneus;
    }
    public String getModelo() {
        return this.modelo;
    }
    public String getPlaca() {
        return this.placa;
    }
    public void setAno(int ano) {
        this.ano = ano;
    }
    public void setQuantPneus(int quantPneus) {
        this.quantPneus = quantPneus;
    }
    public void setModelo(String modelo) {
        this.modelo = modelo;
    }
    public void setPlaca(String placa) {
        this.placa = placa;
    }
    
}
