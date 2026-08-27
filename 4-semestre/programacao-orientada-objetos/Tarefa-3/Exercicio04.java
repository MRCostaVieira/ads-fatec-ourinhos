// Mudanças em relação Exerciico03.java:
// - Palavra escolhida aleatoriamente entre n palavras;
// - Dicas. A lingua portuguesa brasileira possui na média 390 mil palavras. A chance de
//   acertar uma palavra específica é de 0,000002564102564102564%, isso se a
//   palavra for da língua portuguesa, coisa que o programa também não informa.

import java.util.Random;

public class Exercicio04 {

    public static void main(String[] args) {

        String[] palavras = { "Pizza", "Celular", "Caneca", "Blusa", "Remédio", "" };
        Random random = new Random();

        String palavraEscolhida = palavras[random.nextInt(palavras.length)];
    }
}