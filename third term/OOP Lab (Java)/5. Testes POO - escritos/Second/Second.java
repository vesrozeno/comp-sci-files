import java.util.Scanner;
public class Second
{
	public static void main(String[]args)
	{
		Scanner imput = new Scanner(System.in);
		
		double a,b,c,x1,x2,delta;
		
		System.out.print("Digite o valor de a -> ");
		a = imput.nextDouble();
		System.out.print("Digite o valor de b -> ");
		b = imput.nextDouble();
		System.out.print("Digite o valor de c -> ");
		c = imput.nextDouble();
		
		delta = (b*b)-(4*a*c);
		if(a==0)
		{
			System.out.println("Nao eh de segundo grau");
		}
		else if(delta<0)
		{
			System.out.println("Não possui raízes reais!");
		}
		else if(delta==0)
		{
			x1 = (b*(-1))/(2*a);
			System.out.println("\n\ndelta ="+delta+"\n\nx = "+x1);
		}
		else
		{
			x1 = (b*(-1))+(Math.sqrt(delta))/(2*a);
			x2 = (b*(-1))-(Math.sqrt(delta))/(2*a);
			System.out.println("\n\ndelta ="+delta+"\n\nx = "+x1+"\n\nx2 = "+x2);
		}
	
	}
}