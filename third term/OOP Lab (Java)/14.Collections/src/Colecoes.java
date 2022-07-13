import java.util.*;
public class Colecoes {
    public static void main(String[] args)
    {
        List<String> nomes = new ArrayList<>();
        nomes.add("Jao");
        nomes.add("Ana");
        nomes.add("Coragem o cao covarde");
        nomes.add("a");
        nomes.add("b");
        nomes.add("ab");
        nomes.add("aa");



        Integer [] numerosArray = {9,3,2,1,0,5,7,8,4,32,4,5,6,7,5,4325,2,32,42,52,5,23,532,5,32,53};
        List<Integer> numeros = Arrays.asList(numerosArray);


        System.out.println(numeros+"\n\n");
        System.out.println(nomes+"\n\n");

        Collections.sort(nomes);
        System.out.println(nomes+"\n\n");

        Collections.sort(nomes, Collections.reverseOrder());
        System.out.println(nomes+"\n\n");


        Collections.sort(numeros, Collections.reverseOrder());
        System.out.println(numeros+"\n\n");

        Collections.sort(numeros);
        System.out.println(numeros+"\n\n");

        List<Pessoa> pessoas = new ArrayList<>();
        Pessoa jao = new Pessoa("Jao",55,5000);
        Pessoa alirio = new Pessoa("Alirio",12,0);
        Pessoa clebe = new Pessoa("Clebe",32,10000);

        pessoas.add(jao);
        pessoas.add(alirio);
        pessoas.add(clebe);

        Collections.sort(pessoas);
        System.out.println("Ordenação por salário:\n\n");


        for(Pessoa p:pessoas)
        {
            System.out.println(p.getNome()+" "+p.getIdade()+" "+p.getSalario()+"\n\n");
        }

        Collections.shuffle(pessoas);
        System.out.println("Ordenação Shuffle:\n\n");


        for(Pessoa p:pessoas)
        {
            System.out.println(p.getNome()+" "+p.getIdade()+" "+p.getSalario()+"\n\n");
        }

        Collections.reverse(pessoas);
        System.out.println("Ordenação Reverse:\n\n");


        for(Pessoa p:pessoas)
        {
            System.out.println(p.getNome()+" "+p.getIdade()+" "+p.getSalario()+"\n\n");
        }

        Set<String> racas = new HashSet<>();//Sem duplicatas;
        racas.add("Pitbull");
        racas.add("ViraLata");
        racas.add("Bulldog");
        racas.add("Bulldog");

        for(String raca: racas)
        {
            System.out.println(raca);
        }


        System.out.println("\n\n");

        Iterator <String> iterador = racas.iterator();
        while(iterador.hasNext())

        {
            System.out.println(iterador.next());
        }

        Iterator<Pessoa> itPessoa = pessoas.iterator();
        while(itPessoa.hasNext())
        {
            Pessoa p=itPessoa.next();
            System.out.println(p.getNome()+" "+p.getIdade()+" "+p.getSalario()+" ");
        }



    }
    
}
