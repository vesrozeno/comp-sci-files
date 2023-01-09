import java.util.Scanner;
public class Imc
{
	public static void main(String[]args)
	{
		Scanner imput = new Scanner(System.in);
		double peso;
		double altura;
		System.out.print("Digite seu peso (Kg) -> ");
		peso = imput.nextDouble();
		System.out.print("Digite sua altura (m) -> ");
		altura = imput.nextDouble();
		double imc;
		imc = peso/(altura*altura);
		if(imc<18.5)
		{
			System.out.println("IMC: "+imc+" --> abaixo do peso.");
		}
		else if(imc>=18.5&&imc<=24.9)
		{
			System.out.println("IMC: "+imc+" --> normal.");
		}
		else if(imc>=25&&imc<=29.9)
		{
			System.out.println("IMC: "+imc+" --> sobrepeso.");
		}
		else
		{
			System.out.println("IMC: "+imc+" --> obeso.");
		}

	}
}