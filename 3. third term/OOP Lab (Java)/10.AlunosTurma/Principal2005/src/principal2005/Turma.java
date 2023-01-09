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
public class Turma {
    
    
    private String nomeTurma;
    ArrayList<Aluno>alunos = new ArrayList<>();
    
    //CONSTRUTORES---------------------------------
    public Turma(String nomeTurma)
    {
        this.nomeTurma = nomeTurma;
    }
    public Turma()
    {
        this("");
    }
    //----------------------------------------------
    
    public void addAluno()
    {
        Scanner sc = new Scanner(System.in);
        int ra;
        String nome;
        
        Aluno temp;
        
        System.out.print("\nNome do aluno: ");
        nome = sc.nextLine();
        
        System.out.print("\nRa: ");
        ra = sc.nextInt();
        
        temp = new Aluno(nome, ra);
        
        alunos.add(temp);
    }
    public void exibeTurma()
    {
       int i;
       System.out.print("\n\n");
       for(i = 0;i<alunos.size();i++)
       {
            System.out.print("["+alunos.get(i).getNome()+"]");
        }
       System.out.println("\n");
    }
}
