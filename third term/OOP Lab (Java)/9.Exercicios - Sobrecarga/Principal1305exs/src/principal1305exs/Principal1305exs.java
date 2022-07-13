/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal1305exs;
import java.util.Scanner;
/**
 *
 * @author vesrozeno
 */
public class Principal1305exs {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Motorista a = new Motorista("Jonas", 213214, "Sao Paulo", "AB", 5, true);
        //System.out.println("Nome: "+a.getNome()+"\nCNH: "+a.getCnh()+"\nCidade: "+a.getCidade()+"\nTipo: "+a.getTipo()+"\nValidade: "+a.getValidade()+" anos \n"+a.getPermOuDef());
        
        Motorista b = new Motorista("Roberto");
        //System.out.println(b.getNome()+"\n"+b.getCnh()+"\n"+b.getCidade() +"\n"+b.getTipo()+"\n"+b.getValidade()+"\n"+b.getPermOuDef());
        
        Scanner imput = new Scanner(System.in);
        
        
        
        Calculo num = new Calculo();
        Calculo numD = new Calculo ();
        
        
        System.out.println(num.div(10,10));
        System.out.println(numD.div(10.5,20.8));

    
    }
    
    
}
