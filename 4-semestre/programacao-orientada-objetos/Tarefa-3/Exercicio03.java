// Pequeno jogo de adivinhação.
// Escolha uma palavra secreta.
// Defina um número mínimo de tentativas para cada execução do programa.
// O programa deve informar:
// a. a quantidade de letras da palavra secreta;
// b. se a tentativa está correta ou incorreta;
// c. o número restante de tentativas.
// O jogo encerra caso o jogador acerte a palavra secreta ou caso o número de
// tentativas se esgote.
// Exemplo de execução:

// A palavra secreta possui 10 letras.
//
// Tentativa 1: teclado
// Palavra incorreta.
// Tentativa 2: internet
// Palavra incorreta.
//
// Tentativa 3: programa
// Palavra incorreta.
//
// Fim de jogo! Infelizmente você não descobriu a palavra secreta!

import java.util.Scanner;

public class Exercicio03 {

    public static void main(String[] args) {

        String palavraEscolhida = "Pizza";
        int tentativasRestantes = 10;
        boolean executarPrograma = true;

        System.out.println("A palavra secreta possui " + palavraEscolhida.length() + " letras\n");

        while (executarPrograma) {
            int i = 1;

            System.out.println("Tentativa " + i + ":");

        }

    }
}