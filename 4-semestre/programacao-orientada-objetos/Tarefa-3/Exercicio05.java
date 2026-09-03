// Exercício 5 - Jogo da forca simplificado para dois jogadores.
//
// Jogador 1 digita a palavra secreta -> tela é limpa -> Jogador 2 tenta
// descobrir a palavra, uma letra por vez, até acertar tudo ou esgotar o
// número máximo de tentativas (erros).
//
// Dificuldade extra: a partir da 3ª tentativa, uma mensagem extra
// (aleatória, via Math.random + switch-case) é exibida ao Jogador 2.

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Exercicio05 {

    private static final int MAX_ERROS = 6;

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Jogador 1, digite a palavra secreta: ");
        String palavraSecreta = scanner.nextLine().trim().toLowerCase();

        while (palavraSecreta.isEmpty()) {
            System.out.print("Palavra inválida! Digite novamente: ");
            palavraSecreta = scanner.nextLine().trim().toLowerCase();
        }

        limparTela();

        boolean[] descobertas = new boolean[palavraSecreta.length()];
        Set<Character> letrasUtilizadas = new HashSet<>();

        int erros = 0;
        int tentativas = 0;
        boolean venceu = false;

        while (erros < MAX_ERROS) {

            System.out.println("JOGADOR 2");
            System.out.println("Palavra:");
            System.out.println(construirMascara(palavraSecreta, descobertas));

            if (!letrasUtilizadas.isEmpty()) {
                System.out.println("Letras utilizadas: " + formatarLetrasUtilizadas(letrasUtilizadas));
            }

            System.out.println("Erros: " + erros + "/" + MAX_ERROS);

            // Dificuldade extra: a partir da 3ª tentativa, mostra uma mensagem extra aleatória
            if (tentativas >= 3) {
                System.out.println(mensagemExtra(tentativas, erros, letrasUtilizadas));
            }

            System.out.print("Digite uma letra: ");
            String entrada = scanner.nextLine().trim().toLowerCase();

            if (entrada.length() != 1 || !Character.isLetter(entrada.charAt(0))) {
                limparTela();
                System.out.println("Entrada inválida! Digite apenas uma letra.\n");
                continue;
            }

            char letra = entrada.charAt(0);

            if (letrasUtilizadas.contains(letra)) {
                limparTela();
                System.out.println("Você já tentou a letra \"" + letra + "\". Tente outra.\n");
                continue;
            }

            letrasUtilizadas.add(letra);
            tentativas++;

            boolean acertou = revelarLetra(palavraSecreta, descobertas, letra);

            if (!acertou) {
                erros++;
            }

            limparTela();

            if (todasDescobertas(descobertas)) {
                venceu = true;
                break;
            }
        }

        // Estado final
        System.out.println("JOGADOR 2");
        System.out.println("Palavra:");
        System.out.println(construirMascara(palavraSecreta, descobertas));
        System.out.println("Erros: " + erros + "/" + MAX_ERROS);

        if (venceu) {
            System.out.println("\nParabéns! Você descobriu a palavra: " + palavraSecreta);
        } else {
            System.out.println("\nFim de jogo! A palavra era: " + palavraSecreta);
        }

        scanner.close();
    }

    // Marca todas as posições da palavra que correspondem à letra informada.
    // Retorna true se a letra existe na palavra (acerto), false caso contrário.
    private static boolean revelarLetra(String palavra, boolean[] descobertas, char letra) {
        boolean acertou = false;

        for (int i = 0; i < palavra.length(); i++) {
            if (palavra.charAt(i) == letra) {
                descobertas[i] = true;
                acertou = true;
            }
        }

        return acertou;
    }

    private static boolean todasDescobertas(boolean[] descobertas) {
        for (boolean descoberta : descobertas) {
            if (!descoberta) {
                return false;
            }
        }
        return true;
    }

    // Monta a máscara da palavra, ex: "_ o _ _ _ _ a _ o _"
    private static String construirMascara(String palavra, boolean[] descobertas) {
        StringBuilder mascara = new StringBuilder();

        for (int i = 0; i < palavra.length(); i++) {
            mascara.append(descobertas[i] ? palavra.charAt(i) : '_');
            if (i < palavra.length() - 1) {
                mascara.append(' ');
            }
        }

        return mascara.toString();
    }

    private static String formatarLetrasUtilizadas(Set<Character> letras) {
        StringBuilder sb = new StringBuilder();
        boolean primeira = true;

        for (char letra : letras) {
            if (!primeira) {
                sb.append(", ");
            }
            sb.append(letra);
            primeira = false;
        }

        return sb.toString();
    }

    // Sorteia uma entre três mensagens extras usando Math.random + switch-case.
    private static String mensagemExtra(int tentativas, int erros, Set<Character> letrasUtilizadas) {
        int opcao = (int) (Math.random() * 3); // 0, 1 ou 2

        switch (opcao) {
            case 0:
                return "[Dica] Você já fez " + tentativas + " tentativa(s).";
            case 1:
                int restantes = MAX_ERROS - erros;
                return "[Dica] Você ainda pode errar " + restantes + " vez(es) antes de perder.";
            case 2:
                return "[Dica] Letras já usadas: " + formatarLetrasUtilizadas(letrasUtilizadas);
            default:
                return "";
        }
    }

    // Tenta limpar o terminal. Em terminais que suportam ANSI (Linux/Mac e
    // terminais modernos do Windows) a sequência abaixo limpa a tela de fato.
    // Como fallback, imprime várias quebras de linha para "empurrar" o
    // conteúdo anterior para fora da visão.
    private static void limparTela() {
        System.out.print("\033[H\033[2J");
        System.out.flush();

        for (int i = 0; i < 50; i++) {
            System.out.println();
        }
    }
}