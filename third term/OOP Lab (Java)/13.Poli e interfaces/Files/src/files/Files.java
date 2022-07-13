/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package files;
/**
 *
 * @author vesrozeno
 */
import java.io.*;
import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
public class Files {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String filename = "carros.txt";
        Carro fusca = new Carro("FUSCAO");
        Carro clio = new Carro("BIG CLIO");
        
        try
        {
            File arq = new File(filename);
            FileWriter escritor = new FileWriter(arq, false);
            escritor.write(fusca.getModelo()+ "\n");
            escritor.write("\n" + clio.getModelo());

            escritor.close();
            
            
        }
        catch(IOException e)
        {
            System.out.print("Erro" + e);
        }
        
        
        //Leitura
        try
        {
            FileReader arq = new FileReader(filename);
            BufferedReader leitor = new BufferedReader(arq);
            while(leitor.ready())
            {
                
                String tempModelo;
                
                String linhaLida = leitor.readLine();
                String[] linhaSplit = linhaLida.split(";");
                tempModelo = linhaSplit[0];
                
                Carro tempCarro = new Carro(tempModelo);
                
                System.out.println("Nome com get:" + tempCarro.getModelo());
                
                
                
                System.out.print(leitor.readLine());
            }
            
            
            leitor.close();
        }
        catch(IOException e)
        {
            System.out.print("Erro" + e);
        }
        
        
        
        
    }
    
}
