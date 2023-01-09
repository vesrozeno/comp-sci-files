/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal1305;

/**
 *
 * @author vesrozeno
 */
public class Telefone {
    private String modelo;
    private double creditoInicial;
    private int arm;

        
    public Telefone(String modelo, double creditoInicial, int arm)
    {
        this.modelo = modelo;
        this.creditoInicial = creditoInicial;
        this.arm = arm;
    }
    public Telefone(String modelo, double creditoInicial)
    {
        this(modelo, creditoInicial, 0);
    }
    public Telefone(String modelo, int arm)
    {
        this(modelo, 0.0, arm);
    }
    
    public String getModelo()
    {
        return this.modelo;
    }
    public double getCreditoInicial()
    {
        return this.creditoInicial;
    }
    public int getArm()
    {
        return this.arm;
    }
}
