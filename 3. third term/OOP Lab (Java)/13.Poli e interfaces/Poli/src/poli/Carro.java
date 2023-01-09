package poli;

/**
 *
 * @author vesrozeno
 */
public class Carro extends Veiculo {
    String proprietario;
    int ultimaRevisao;
    
    public Carro(int ano, int quantPneus, String modelo, String placa, String proprietario, int ultimaRevisao)
    {
        super(ano, quantPneus, modelo, placa);
        this.proprietario = proprietario;
        this.ultimaRevisao = ultimaRevisao;
    }
}
