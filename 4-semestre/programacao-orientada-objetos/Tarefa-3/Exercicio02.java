// Faça um programa que leia uma palavra, construa a sua versão invertida e informe se ela é um palíndromo ou não.
// Exemplo de execução:
// Digite uma palavra: Java
// Palavra invertida: avaJ
// A palavra não é um palíndromo.

import java.util.Scanner;

public class Exercicio02 {

    public static void main(String[] args) {

        String palavra;
        String palavraInvertida = "";

        try (Scanner scanner = new Scanner(System.in)) { // try automaticamente executa scanner.close()

            System.out.print("Digite uma palavra: ");
            palavra = scanner.nextLine().trim(); // trim() remove espaços em branco no início e final da string
        }

        if (palavra == null || palavra.isEmpty()) { // verificar se palavra foi corretamente escrita
            System.out.println("Palavra inválida!");
            return;
        }

        for (int i = palavra.length() - 1; i >= 0; i--) {
            palavraInvertida += palavra.charAt(i);
        }

        System.out.println("Palavra invertida: " + palavraInvertida);

        if (palavra.contains(palavraInvertida)) {
            System.out.println("A palavra é um palíndromo.");
        } else {
            System.out.println("A palavra não é um palíndromo.");
        }

    }
}