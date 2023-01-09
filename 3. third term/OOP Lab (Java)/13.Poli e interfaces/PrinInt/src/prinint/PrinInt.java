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
public class PrinInt {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Televisao sam = new Televisao(2000,"Sam");
        
        System.out.println("Nome:"+ sam.getNome());
        System.out.println("Preco:"+ sam.getPreco());
        
    }
    
}
