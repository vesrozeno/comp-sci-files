package xadrez;

/**
 *
 * @author vesrozeno
 */
public abstract class Peca {
    
    private String nome;
    public abstract void mover();

    public Peca(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    
    
    
}
