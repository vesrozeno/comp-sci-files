/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package xadrez;

/**
 *
 * @author vesrozeno
 */
public class Cavalo extends Peca {

    public Cavalo(String nome) {
        super(nome);
    }
    
    @Override
    public void mover()
    {
        System.out.println("Andar em L");
    }
    
}
