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
public class Principal1305 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Telefone nokia = new Telefone("Nokia", 10.2);
        Telefone samsung = new Telefone("Samsung", 64);
        System.out.println("Modelo: "+nokia.getModelo()+"\nCredito: "+nokia.getCreditoInicial());
        System.out.println("Modelo: "+samsung.getModelo() + "\nArmazenamento: " + samsung.getArm()+"GB");

    }
    
}
