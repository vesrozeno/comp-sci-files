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
public class Artropode extends Animal {

    public Artropode(String nome) {
        super(nome);
    }
    @Override
    public void comunicar()
    {
        System.out.println("aaaaaaaaaaaaaaaaa");
        
    }
    @Override
    public void movimentar()
    {
        System.out.println("artropode se movendo uau");
    }
}
