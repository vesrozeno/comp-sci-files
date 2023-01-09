/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prinani;

/**
 *
 * @author vesrozeno
 */
public class Peixe extends Animal {

    public Peixe(String nome) {
        super(nome);
    }
    
    @Override
    public void comunicar()
    {
        System.out.println("pexe");
        
    }
    @Override
    public void movimentar()
    {
        System.out.println("Nada");
    }
}
