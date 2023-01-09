import java.util.Scanner;
public class Principal
{
	public static void main(String[]args)
	{
		Scanner imput = new Scanner(System.in);
		Cadastro pessoa1 = new Cadastro();
		
		pessoa1.setNome(imput.nextString());
		System.out.println(pessoa1.getNome());
	}
}