import java.util.Scanner;//util = utilitários
public class IO
{
	public static void main(String args[])
	{
		double valor;//atributo valor, tipo double
		Scanner sc = new Scanner(System.in);// novo objeto; classe scanner; método de entrada
		System.out.println("Digite o valor: ");
		valor = sc.nextDouble();//next"Tipo"
		//java trabalha com double ---> para float = "x = 1.5f"
		System.out.println("O valor digitado foi "+valor);
	}
}