// 1. Escreva um programa que leia uma palavra digitada pelo usuário e apresente:
// a.	a palavra em letras maiúsculas;
// b.	a palavra em letras minúsculas;
// c.	a quantidade de caracteres;
// d.	o primeiro caractere;
// e.	o último caractere.

import java.util.Scanner;

public class Exercicio01 {

    public static void main(String[] args) {

        String palavra;

        try (Scanner scanner = new Scanner(System.in)) { // try automaticamente executa scanner.close()

            System.out.print("Digite uma palavra: ");
            palavra = scanner.nextLine().trim(); // trim() remove espaços em branco no início e final da string
        }

        if (palavra == null || palavra.isEmpty()) { // verificar se palavra foi corretamente escrita
            System.out.println("Palavra inválida!");
            return;
        }

        System.err.println("Maiúsculas: " + palavra.toUpperCase());
        System.err.println("Maiúsculas: " + palavra.toLowerCase());
        System.err.println("Quantidade de caracteres: " + palavra.replace(" ", "").length());
        System.err.println("Primeiro caractere: " + palavra.charAt(0));
        System.err.println("Último caractere: " + palavra.charAt(palavra.length() - 1));
    }
}