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
public class Xadrez {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Cavalo c = new Cavalo("Cavalo");
        Peao p = new Peao("Peao");
        
        
        c.mover();
        p.mover();
    }
    
}
