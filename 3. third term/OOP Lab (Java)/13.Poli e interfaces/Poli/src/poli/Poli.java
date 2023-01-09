/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poli;

/**
 *
 * @author vesrozeno
 */
public class Poli {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Carro v = new Carro(2010, 4, "onix", "kee7601","jose",2019);
        System.out.print("\nPedagio: " + calculaPedagio(v)+ "\n");
        
        
    }
    public static double calculaPedagio(Veiculo v)
        {
            double pedagio;
            if(v instanceof Carro)
            {
                pedagio = 1.5 * v.getQuantPneus();
                
            }
            else
            {
                pedagio = 11.87;
            }
            return pedagio;
        }
    
}
