import java.util.Scanner;

public class igualMaiorZero {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int n = 0;
        double avg = 0;

        while (n >= 0) {
            System.out.println("Insira um número inteiro igual ou maior que 0.");
            System.out.print("Número: ");

            avg += n;

            n = scanner.nextInt();
        }

        System.out.println("Falei maior que 0.");
        System.out.println("Média: " + (avg / 2.0));
        scanner.close();
    }
}
