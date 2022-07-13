public class Cachorro
{
		String nome;
		String raca;
		String corDoPelo;
		int idade;
	void latir()
	{
		System.out.println("au.");
	}
	void latirScooby()
	{
		System.out.println("scoobydoobydooooo au.");
	}
	void dormir()
	{
		System.out.println("zzzZZZzzz....");
	}
	void comer()
	{
		System.out.println("-cachorro comendo-");
	}
	public static void main(String args[])
	{
		Cachorro bonita = new Cachorro();
		bonita.latir();
		bonita.dormir();
		bonita.comer();
		
		Cachorro scooby = new Cachorro();
		scooby.latirScooby();
	}
	 
}