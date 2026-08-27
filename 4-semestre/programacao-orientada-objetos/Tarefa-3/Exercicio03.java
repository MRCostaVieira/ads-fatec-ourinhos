// Pequeno jogo de adivinhação.
// Escolha uma palavra secreta.
// Defina um número mínimo de tentativas para cada execução do programa.
// O programa deve informar:
// a. a quantidade de letras da palavra secreta;
// b. se a tentativa está correta ou incorreta;
// c. o número restante de tentativas.
// O jogo encerra caso o jogador acerte a palavra secreta ou caso o número de tentativas se esgote.

import java.util.Scanner;

public class Exercicio03 {

    public static void main(String[] args) {

        String palavraSecreta = "Pizza";

        int tentativasRestantes = 10;
        int tentativaAtual = 1;

        boolean executarPrograma = true;

        Scanner scanner = new Scanner(System.in);

        System.out.println("A palavra secreta possui " + palavraSecreta.length() + " letras\n");

        while (executarPrograma) {

            String respostaJogador = "";

            if (tentativasRestantes == 0) {
                System.out.println("Suas chances acabaram!");
                executarPrograma = false;
                break;
            }

            System.out.print("Tentativa " + tentativaAtual + ": ");
            respostaJogador = scanner.nextLine().trim();

            // verificar se respostaJogador foi corretamente escrita
            if (respostaJogador == null || respostaJogador.isEmpty()) {
                System.out.println("Palavra inválida!");
                continue;
            }

            int ponteiroReversoRespostaJogador = respostaJogador.length() - 1;

            for (int i = 0; i < palavraSecreta.length(); i++) {

                if (palavraSecreta.charAt(i) != respostaJogador.charAt(ponteiroReversoRespostaJogador)) {

                    tentativasRestantes--;

                    if (tentativasRestantes >= 1) { // Se for a última chance, só ira aparecer "Suas chances acabaram"
                        System.out.println("Resposta errada. Você tem mais " + tentativasRestantes + " tentativas!");
                    }

                    break;
                }

                ponteiroReversoRespostaJogador--;
            }

            if (palavraSecreta.contains(respostaJogador)) {

                System.out.println("Resposta correta. Parabens!");
                executarPrograma = false;
            }

            tentativaAtual++;

        }

        scanner.close();

    }
}