public class Principal
{
	public static void main(String[]args)
	{
		Carro fusca = new Carro();
		Carro onix = new Carro();
		Carro ka = new Carro();
		Carro celta = new Carro();
		
		
		fusca.setNome("Fusca");
		fusca.setMarca("Volks");
		fusca.setPeso(1000f);
		fusca.setKm(132421f);
		
		onix.setNome("Onix");
		onix.setMarca("Chevrolet");
		onix.setPeso(1500f);
		onix.setKm(90f);

		
		ka.setNome("Ka");
		ka.setMarca("Ford");
		ka.setPeso(1050f);
		ka.setKm(1398f);

		celta.setNome("Celta");
		celta.setMarca("Chevrolet");
		celta.setPeso(1930f);
		celta.setKm(100f);

		
		System.out.println(fusca.getNome());
		System.out.println(fusca.getMarca());
		System.out.println(fusca.getPeso());
		System.out.println(fusca.getKm());
		
		System.out.println("\n\n\n");
		
		System.out.println(onix.getNome());
		System.out.println(onix.getMarca());
		System.out.println(onix.getPeso());
		System.out.println(onix.getKm());
		
		System.out.println("\n\n\n");
		
		System.out.println(ka.getNome());
		System.out.println(ka.getMarca());
		System.out.println(ka.getPeso());
		System.out.println(ka.getKm());
		
		System.out.println("\n\n\n");
		
		System.out.println(celta.getNome());
		System.out.println(celta.getMarca());
		System.out.println(celta.getPeso());
		System.out.println(celta.getKm());
		
		System.out.println("\n\n\n");
		
		fusca.acelerar();
		
		onix.buzinar();

	}
}