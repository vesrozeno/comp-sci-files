import java.util.*;
public class Livro {

    private int isbn;
    private String titulo;
    private String autor;
    private String editora;
    private int nPags;
    private int ano;

    public int getIsbn() {
        return isbn;
    }
    public void setIsbn(int isbn) {
        this.isbn = isbn;
    }
    public String getTitulo() {
        return titulo;
    }
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    public String getAutor() {
        return autor;
    }
    public void setAutor(String autor) {
        this.autor = autor;
    }
    public String getEditora() {
        return editora;
    }
    public void setEditora(String editora) {
        this.editora = editora;
    }
    public int getnPags() {
        return nPags;
    }
    public void setnPags(int nPags) {
        this.nPags = nPags;
    }
    public int getAno() {
        return ano;
    }
    public void setAno(int ano) {
        this.ano = ano;
    }
    public Livro(int isbn, String titulo, String autor, String editora, int nPags, int ano) {
        this.isbn = isbn;
        this.titulo = titulo;
        this.autor = autor;
        this.editora = editora;
        this.nPags = nPags;
        this.ano = ano;
    }

    Livro um = new Livro(123,"a","b","c",2,2010);
    Livro dois = new Livro(345,"d","e","f",3,2012);
    Livro tres = new Livro(678,"g","h","i",4,1990);


    Map<Integer,Livro>livros =new HashMap<Integer,Livro>();

    livros.put(123,um);





    
}
