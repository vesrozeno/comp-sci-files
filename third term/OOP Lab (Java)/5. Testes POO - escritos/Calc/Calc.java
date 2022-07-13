import java.util.Scanner;
public class Calc
{
	public static void main(String[]args)
	{
		Scanner imput = new Scanner(System.in);
		int num;
		int quad;
		int cubo;
		System.out.print("Digite um numero -> ");
		num = imput.nextInt();
		quad = num*num;
		cubo = quad*num;
		System.out.println("Quadrado de "+num+" = "+quad+"\nCubo de "+num+" = "+cubo);
	}
}