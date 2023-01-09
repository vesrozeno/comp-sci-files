import java.util.HashMap;
import java.util.Map;

public class Carro {
    private String placa;
    private String nome;
    private int ano;

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public Carro(String placa, String nome, int ano) {
        this.placa = placa;
        this.nome = nome;
        this.ano = ano;
    }

    Carro corsa = new Carro("AC2-1234","Corsa",1999);
    Carro uno = new Carro("XYA-SA221","Uno",2001);

    Map<String,Carro> carros = new HashMap<>();
    //Não é instanciada diretamente - usa-se hashmap

    //carros.put("AC2-1234",corsa);
    //carros.put("XYA-SA221",uno);

    //Carro pesquisa = carros.get("XYA-SA221");



    


}
