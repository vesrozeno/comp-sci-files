/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal2005;
import java.util.ArrayList;
import java.util.Scanner;
/**
 *
 * @author vesrozeno
 */
public class Principal2005 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        Turma bcc21;
        bcc21 = new Turma("BCC21");
        int choose = 0;
        
        while(choose!=3)
        {
            System.out.print("\n[1]Adicionar Aluno\n[2]Exibir Turma\n[3]Sair\n------> ");
            choose = sc.nextInt();
            
            switch(choose)
            {
                case 1: bcc21.addAluno();
                    break;
                case 2: bcc21.exibeTurma();
                    break;
                case 3:
                    break;
                default: System.out.println("Entrada invalida");
            }
        }
    }
    
}
