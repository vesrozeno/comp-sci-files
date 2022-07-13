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
public class Calculo {
    private int a;
    private int b;
    private double c;
    private double d;
    
    public Calculo()
    {
     this(0,0,0.0,0.0);
    }
    public Calculo(int a, int b, double c, double d)
    {
     this.a = a;
     this.b = b;
     this.c = c;
     this.d = d;
    }
    public Calculo(int a, int b)
    {
     this(a,b,0.0,0.0);
    }
    public Calculo(double c, double d)
    {
     this(0,0,c,d);
    }
    public int soma(int a, int b)
    {
        return a+b;
    }
    public double soma(double a, double b)
    {
        return a+b;
    }
    
    
    
    public int sub(int a, int b)
    {
        return a-b;
    }
    public double sub(double a, double b)
    {
        return a-b;
    }
    
    
    public int mult(int a, int b)
    {
        return a*b;
    }
    public double mult(double a, double b)
    {
        return a*b;
    }
    
    
    
    public double div(int a, int b)
    {
        return a/b;
    }
    public double div(double a, double b)
    {
        return a/b;
    }
    
    
    public void setNum(int a,int b,int c,int d)
    {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }
    
    
}
