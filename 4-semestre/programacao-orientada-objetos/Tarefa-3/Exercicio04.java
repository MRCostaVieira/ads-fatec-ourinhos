import java.util.Random;
import java.util.stream.IntStream;

public class Exercicio04 {

    public static void main(String[] args) {

        String[] palavras = { "Pizza", "Celular", "Caneca", "Blusa", "Remédio", "" };
        Random random = new Random();

        String palavraEscolhida = palavras[random.nextInt(palavras.length)];
    }
}