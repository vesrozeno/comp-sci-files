public class Carro
{
	//ATRIBUTOS---------------------------
	private String nome;
	private String marca;
	private float peso;
	private float km;
	private String cor;
	private int numChassi;
	private int aroPneu;
	
	//GETTERS AND SETTERS-----------------------------------------------------
	public void setNome(String nome)
	{
		this.nome = nome;//nome do parâmetro x nome do atributo
	}
	public String getNome()
	{
		return this.nome;
	}
	
	public void setMarca(String marca)
	{
		this.marca = marca;//nome do parâmetro x nome do atributo
	}
	public String getMarca()
	{
		return this.marca;
	}
	
	public void setKm(float km)
	{
		this.km = km;//nome do parâmetro x nome do atributo
	}
	public float getKm()
	{
		return this.km;
	}
	
	public void setPeso(float peso)
	{
		this.peso = peso;//nome do parâmetro x nome do atributo
	}
	public float getPeso()
	{
		return this.peso;
	}
	//-----------------------------------------------------------------------
	
	//MÉTODOS------------------------
	public void acelerar()
	{
		System.out.println(this.nome+" acelera.");
	}
	public void buzinar()
	{
		System.out.println(this.nome+" buzina.");
	}
}