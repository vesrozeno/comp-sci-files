/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal2005;
import java.util.ArrayList;
import java.util.ArrayList;
/**
 *
 * @author vesrozeno
 */
public class Aluno {
    
    private String nome;
    private int ra;
    
    
    public Aluno(String nome, int ra)
    {
        this.nome = nome;
        this.ra = ra;
    }
    public Aluno(String nome)
    {
        this(nome,0);
    }
    public Aluno(int ra)
    {
        this("",ra);
    }
    public Aluno()
    {
        this(0);
    }
    public String getNome()
    {
        return this.nome;
    }
    public int getRa()
    {
        return this.ra;
    }
    
    public void setNome(String nome)
    {
        this.nome = nome;
    }
    
    public void setRa(int ra)
    {
        this.ra = ra;
    }
}
