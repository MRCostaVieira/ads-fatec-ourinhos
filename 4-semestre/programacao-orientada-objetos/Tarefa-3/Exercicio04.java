// Jogo de adivinhação (versão melhorada).
// Mudanças em relação ao Exercicio03.java original:
// - Palavra escolhida aleatoriamente entre n palavras;
// - Dicas liberadas a cada erro, já que a chance de acertar uma palavra
//   "no escuro" é extremamente baixa (~0,0000025% considerando as ~390 mil
//   palavras da língua portuguesa).

import java.util.Random;
import java.util.Scanner;

public class Exercicio04 {

    // Cada palavra secreta tem uma categoria/tema associado, usado como
    // primeira dica.
    private static final String[] PALAVRAS = {
        "Pizza", "Abacaxi", "Computador", "Elefante", "Girafa",
        "Chocolate", "Guitarra", "Foguete", "Montanha", "Borboleta"
    };

    private static final String[] CATEGORIAS = {
        "Comida", "Fruta", "Tecnologia", "Animal", "Animal",
        "Doce", "Instrumento musical", "Meio de transporte", "Acidente geográfico", "Inseto"
    };

    public static void main(String[] args) {

        Random random = new Random();
        int indiceEscolhido = random.nextInt(PALAVRAS.length);

        String palavraSecreta = PALAVRAS[indiceEscolhido];
        String categoria = CATEGORIAS[indiceEscolhido];

        int tentativasRestantes = 10;
        int tentativaAtual = 1;

        boolean executarPrograma = true;

        Scanner scanner = new Scanner(System.in);

        System.out.println("A palavra secreta possui " + palavraSecreta.length() + " letras\n");

        while (executarPrograma) {

            if (tentativasRestantes == 0) {
                System.out.println("Suas chances acabaram! A palavra secreta era: " + palavraSecreta);
                executarPrograma = false;
                break;
            }

            // Mostra uma dica progressiva de acordo com o número de erros já cometidos
            System.out.println(obterDica(palavraSecreta, categoria, tentativaAtual));

            System.out.print("Tentativa " + tentativaAtual + ": ");
            String respostaJogador = scanner.nextLine().trim();

            if (respostaJogador.isEmpty()) {
                System.out.println("Palavra inválida!\n");
                continue;
            }

            if (respostaJogador.equalsIgnoreCase(palavraSecreta)) {
                System.out.println("Resposta correta. Parabéns!");
                executarPrograma = false;
            } else {
                tentativasRestantes--;

                if (tentativasRestantes >= 1) {
                    System.out.println("Resposta errada. Você tem mais " + tentativasRestantes + " tentativa(s)!\n");
                }

                tentativaAtual++;
            }
        }

        scanner.close();
    }

    // Libera uma dica diferente dependendo de quantas tentativas já foram feitas.
    // Quanto mais o jogador erra, mais informação ele recebe.
    private static String obterDica(String palavraSecreta, String categoria, int tentativaAtual) {

        switch (tentativaAtual) {
            case 1:
                return "Dica: a categoria da palavra é \"" + categoria + "\".";
            case 2:
                return "Dica: a palavra começa com a letra \"" + palavraSecreta.charAt(0) + "\".";
            case 3:
                return "Dica: a palavra termina com a letra \"" + palavraSecreta.charAt(palavraSecreta.length() - 1) + "\".";
            default:
                // A partir da 4ª tentativa, revela uma letra "no meio" da palavra,
                // avançando uma posição a cada nova tentativa.
                int posicao = Math.min(tentativaAtual - 3, palavraSecreta.length() - 1);
                return "Dica: a letra na posição " + (posicao + 1) + " é \"" + palavraSecreta.charAt(posicao) + "\".";
        }
    }
}