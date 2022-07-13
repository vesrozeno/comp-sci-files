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
public class PrinAni {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Passaro piu = new Passaro("Piu");
        Peixe nemo = new Peixe("Nemo");
        Mamifero vitor = new Mamifero("Vitor");
        Anfibio sapao = new Anfibio("Big Sapo");
        Artropode spidey = new Artropode("Miranha");
        
        acoes(piu);
        acoes(nemo);
        acoes(vitor);
        acoes(sapao);
        acoes(spidey);
        
    }
    
    public static void acoes(Animal a)
    {
        
        if(a instanceof Animal)
        {
           System.out.println("Animal: "+ a.getNome());
           a.comunicar();
           a.movimentar();
        }
        else
        {
            System.out.println("Nao");
        
        }
    }
    
}
