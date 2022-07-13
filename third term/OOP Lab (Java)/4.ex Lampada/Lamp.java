public class Lamp
{
	boolean ligada;
	
	void liga()
	{
		ligada = true;
	}
	void desliga()
	{
		ligada = false;
	}
	void observa()
	{
		System.out.println("ligada?");
		if(ligada == true)
		{
			System.out.println(" ---> Ligada.");
		}
		else
		{
			System.out.println(" ---> Desligada.");
		}
	}
	public static void main(String args[])
	{
		Lamp lamp1 = new Lamp();
		Lamp lamp2 = new Lamp();
		lamp1.liga();
		lamp1.observa();
		lamp2.desliga();
		lamp2.observa();
	}
}