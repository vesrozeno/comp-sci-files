/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package files;

/**
 *
 * @author vesrozeno
 */
public class Carro {
    
    private String modelo;
    private String cor;
    private String placa;
    private int nChassi;
    private int ano;
    private float nvCombustivel;
    
    public Carro(String modelo)
    {
        this.modelo = modelo;
    }
    //Setters
    public void setModelo(String modelo)
    {
        this.modelo = modelo;
    }
    public void setCor(String cor)
    {
        this.cor = cor;
    }
    public void setPlaca(String placa)
    {
        this.placa = placa;
    }
    public void nChassi(int nChassi)
    {
        this.nChassi = nChassi;
    }
    public void setAno(int ano)
    {
        this.ano = ano;
    }
    public void setNvCombustivel(float nvCombustivel)
    {
        this.nvCombustivel = nvCombustivel;
    }
    
    //Getters
    public String getModelo()
    {
    return this.modelo;
    }
    public String getCor()
    {
    return this.cor;
    }
    public String getPlaca()
    {
    return this.placa;
    }
    public int getNChassi()
    {
    return this.nChassi;
    }
    public int getAno()
    {
    return this.ano;
    }
    public float getNvombustivel()
    {
    return this.nvCombustivel;
    }
    
}    

