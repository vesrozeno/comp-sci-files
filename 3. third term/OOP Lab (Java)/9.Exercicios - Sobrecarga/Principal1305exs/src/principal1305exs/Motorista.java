/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal1305exs;

/**
 *
 * @author vesrozeno
 */
public class Motorista {
    private String nome;
    private int cnh;
    private String cidade;
    private String tipo;
    private int validade;
    private boolean permOuDef;
    
    public Motorista(String nome, int cnh, String cidade, String tipo, int validade, boolean permOuDef)
    {
        this.nome = nome;
        this.cnh = cnh;
        this.cidade  = cidade;
        this.tipo = tipo;
        this.validade = validade;
        this.permOuDef = permOuDef;
    }
    public Motorista(String nome)
    {
        this(nome,0,"null","null",0,false);
    }
    public void setTipoEPermOuDef(String tipo, boolean permOuDef)
    {
        this.tipo = tipo;
        this.permOuDef = permOuDef;
    }
    public String getNome()
    {
        return this.nome;
    }
    public int getCnh()
    {
        return this.cnh;
    }
    public String getCidade()
    {
        return this.cidade;
    }
    public String getTipo()
    {
        return this.tipo;
    }
    public int getValidade()
    {
        return this.validade;
    }
    public String getPermOuDef()
    {
        if(this.permOuDef == true)
        {
            return "permissao";
        }
        else
        {
            return "definitiva";
        }
    }
}   
